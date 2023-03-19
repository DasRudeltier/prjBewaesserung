#define pSDA 21
#define pSCL 22
#define pFAN 26
#define pPUMP 25
#define pUV 14
#define pERDE 32

//I2C Adressen
//0x27 LCD 16x2 Display
//0x40 Temperatur
//0x23 Helligkeitssensor

#define ROTARY_ENCODER_A_PIN 33
#define ROTARY_ENCODER_B_PIN 32
#define ROTARY_ENCODER_BUTTON_PIN 35
#define ROTARY_ENCODER_VCC_PIN 16
#define ROTARY_ENCODER_STEPS 3 //WENN NICHT RICHTIG DANN 1,2,3,4 VERSUCHEN

float temp1 = 0.0;

float _TEMPERATUR = 0;
float _LUFTFEUCHT = 0;
float _ERDFEUCHT = 0;
float _LICHT = 0;
bool DEBUG = false;

bool bFAN;
bool bUV;
bool bPUMP;

int TIMER = 0;

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Arduino.h>
#include <AiEsp32RotaryEncoder.h>
#include <customchars.h>
#include <BH1750.h>
#include <SHT2x.h>

#include <DNSServer.h>
#include <WiFi.h>
#include <AsyncTCP.h>
#include "ESPAsyncWebServer.h"
#include <WEBPAGE.h>
#include <WebSocketsServer.h>
#include <ArduinoJson.h>

LiquidCrystal_I2C lcd(0x27,16,2);
BH1750 lightMeter(0x23);
SHT2x sht;

void webSocketEvent(uint8_t , WStype_t, uint8_t * , size_t );
void sendResponse();
WebSocketsServer webSocket = WebSocketsServer(81); // Create a WebSocketsServer listening to port 81
DNSServer dnsServer;
AsyncWebServer server(80);

bool con = false;                                  // Connection state of WebSocket
boolean bChange = true;                            // Change flag
boolean LED1 = false;                              // Save the current state of LED1

class CaptiveRequestHandler : public AsyncWebHandler {
public:
  CaptiveRequestHandler() {}
  virtual ~CaptiveRequestHandler() {}

  bool canHandle(AsyncWebServerRequest *request){
    //request->addInterestingHeader("ANY");
    return true;
  }

  void handleRequest(AsyncWebServerRequest *request) {
    AsyncResponseStream *response = request->beginResponseStream("text/html");
    response->print(html);
    request->send(response);
  }
};

void LOOP_TIMER(){
  if (TIMER == 10)
  {
    TIMER = 0;
  }else{
    TIMER++;
  }
  delay(100);
}

int var83;
void LCD_TEST(){
  lcd.home();
  lcd.print(var83);
  var83++;
}

void INIT_LCD(){
  lcd.init();
  lcd.backlight();
  lcd.clear();
}

void LCD_WRITE(String EING){
  lcd.home();
  lcd.print("                ");
  lcd.home();
  lcd.print(EING);
}

void INIT_FAN(){
  pinMode(pFAN, OUTPUT);
  if(DEBUG)digitalWrite(pFAN, HIGH);
  if(DEBUG)delay(1500);
  if(DEBUG)digitalWrite(pFAN, LOW);
  LCD_WRITE("FAN Ready!");
}

void INIT_PUMP(){
  pinMode(pPUMP, OUTPUT);
  if(DEBUG)digitalWrite(pPUMP, HIGH);
  if(DEBUG)delay(1500);
  if(DEBUG)digitalWrite(pPUMP, LOW);
  LCD_WRITE("PUMP Ready!");
}

void INIT_LED(){
  pinMode(14, OUTPUT);
  if(DEBUG)digitalWrite(pUV, HIGH);
  if(DEBUG)delay(1500);
  if(DEBUG)digitalWrite(pUV, LOW);
  LCD_WRITE("LED Ready!");
}

void INIT_TEST(){
  LCD_WRITE("TESTING!");
}

void INIT_LIGHT(){
  if (lightMeter.begin(BH1750::CONTINUOUS_HIGH_RES_MODE)) {
    LCD_WRITE("Lichtsen. READY!");
  } else {
    LCD_WRITE("Lichtsen. ERROR!");
  }
}

void INIT_TEMP(){
  sht.begin();
  if(sht.isConnected()){
    LCD_WRITE("Tempsen. READY!");
  }else{
    LCD_WRITE("Tempsen. ERROR!");
  }
}

void FAN(bool anaus){ //EF - Lüfter ein/ausschalten | EIG - true/false
  if(anaus)digitalWrite(pFAN, HIGH);else{digitalWrite(pFAN,LOW);}
}

void TEMP_LESEN(){ //EF - Temperatursensor einlesen und speichern
  bool b = sht.read();
  _TEMPERATUR = sht.getTemperature();
}

void DIRTHUMID_LESEN(){
  _ERDFEUCHT=analogRead(pERDE)/4096.0*100.0;
}

void HUMID_LESEN(){ //EF - Temperatursensor(Feuchtigkeit) einlesen und speichern
  bool b = sht.read();
  _LUFTFEUCHT = sht.getHumidity();
}

void LICHT_LESEN(){
  if (lightMeter.measurementReady()) {
    _LICHT = lightMeter.readLightLevel();
  }
}

void LCD_PREV(){

}

void INIT_SERIAL(){
  Serial.begin(9600);
  LCD_WRITE("SERIAL Ready!");
}

void UPDATE(){
  DIRTHUMID_LESEN();
  TEMP_LESEN();
  HUMID_LESEN();
  LICHT_LESEN();
}

int i = 1;
void CYCLE_INFO(){
  
  if(TIMER == 5 || TIMER == 10){
  UPDATE();
  String sBeschriftung = "";
  switch (i)
  {
  case 1:
    sBeschriftung = "Feucht.: "+String(_LUFTFEUCHT)+"%";
    break;
  case 2:
    sBeschriftung = "Temp.: "+String(_TEMPERATUR)+" \xDF C";
    break;
  case 3:
    sBeschriftung = "Licht: "+String(_LICHT)+" LUX";
    break;
  case 4:
    sBeschriftung = "Erde: "+String(_ERDFEUCHT)+"%";
    i=0;
    break;
  }
  LCD_WRITE(sBeschriftung);
  i++;
  //"TIMER" Abfrage
  }
}

void LOOP_STEUERUNG(){
  UPDATE();

  //~~LÜFTER~~
  if(_TEMPERATUR>24.0||_LUFTFEUCHT>70.0){
    FAN(true);
    bFAN = true;
  }else{
    if(_TEMPERATUR<23.0&&_LUFTFEUCHT<50.0){
      bFAN = false;
      FAN(false);}
  }

  //~~UV~~
  if(_LICHT<45.0){
    digitalWrite(pUV, HIGH);
    bUV = true;
  }else{
    bUV = false;
    digitalWrite(pUV, LOW);
  }

  //~~WASSER~~
  if(_ERDFEUCHT<50.0){
    bPUMP = true;
    digitalWrite(pPUMP, HIGH);
  }else{
    bPUMP = false;
    digitalWrite(pPUMP, LOW);
  }

}

void SERIAL_SEND(){
  Serial.println(String(_TEMPERATUR)+","+String(_ERDFEUCHT)+","+String(_LICHT)+","+String(_LUFTFEUCHT)+","+String(bFAN)+","+String(bUV)+","+String(bPUMP));
}


/*###############################*/
/*####### ROATARY ENCODER #######*/
/*###############################*/
/*                                              ########SPÄTER!########

AiEsp32RotaryEncoder rotaryEncoder = AiEsp32RotaryEncoder(ROTARY_ENCODER_A_PIN, ROTARY_ENCODER_B_PIN, ROTARY_ENCODER_BUTTON_PIN, ROTARY_ENCODER_VCC_PIN, ROTARY_ENCODER_STEPS);

void rotary_onButtonClick()
{
	static unsigned long lastTimePressed = 0;
	//ignore multiple press in that time milliseconds
	if (millis() - lastTimePressed < 500)
	{
		return;
	}
	lastTimePressed = millis();
  lcd.clear();
  lcd.println(millis());
  lcd.print(" milliseconds after restart");
}

void rotary_loop()
{
	//dont print anything unless value changed
	if (rotaryEncoder.encoderChanged())
	{ 
    lcd.clear();
    lcd.print("Value: ");
    lcd.println(rotaryEncoder.readEncoder());
	}
	if (rotaryEncoder.isEncoderButtonClicked())
	{
		rotary_onButtonClick();
	}
}

void IRAM_ATTR readEncoderISR()
{
	rotaryEncoder.readEncoder_ISR();
}

void INIT_RE(){
	rotaryEncoder.begin();
	rotaryEncoder.setup(readEncoderISR);
	bool circleValues = false;
	rotaryEncoder.setBoundaries(0, 3, true); //minValue, maxValue, circleValues true|false (when max go to min and vice versa)
	rotaryEncoder.setAcceleration(0); //or set the value - larger number = more accelearation; 0 or 1 means disabled acceleration
}

*/

//############WEBSERVER#############
//############WEBSERVER#############
//############WEBSERVER#############

void INIT_WEB(){
  //your other setup stuff...
  WiFi.softAP("JaTiMa Bewässerungssystem");
  dnsServer.start(53, "*", WiFi.softAPIP());
  server.addHandler(new CaptiveRequestHandler()).setFilter(ON_AP_FILTER);//only when requested from AP
  //more handlers...
  server.begin();
  webSocket.begin();
  webSocket.onEvent(webSocketEvent);
}

void LOOP_WEB(){
  dnsServer.processNextRequest();
  webSocket.loop();
  if (con == true) {
    sendResponse(); 
  }
}

void webSocketEvent(uint8_t num, WStype_t type, uint8_t *payload, size_t lenght) {
  switch (type) {
    case WStype_DISCONNECTED:
      if(DEBUG)Serial.println("Websocket disconnected!");
      con = false;
      break;

    case WStype_CONNECTED:
      if(DEBUG)Serial.print("Websocket connected to ");
      if(DEBUG)Serial.println(webSocket.remoteIP(num));
      con = true;
      bChange = true;
      break;

    case WStype_TEXT:
      // Receive request from Client
      String text = String((char *) payload);
      if(DEBUG)Serial.println((String)"client " + num + (String)": " + text);
      break;
  }
}

void sendResponse() {
  char buf[128*2];
  DynamicJsonDocument doc(128*2);
  doc["action"] = "response";
  doc["TEMP"] = String(_TEMPERATUR)+"°C";
  doc["LUFE"] = String(_LUFTFEUCHT)+"%";
  doc["ERFE"] = String(_ERDFEUCHT)+"%";
  doc["HELI"] = String(_LICHT)+" LUX";
  doc["PUMP"] = bPUMP ? "An" : "Aus";
  doc["LICH"] = bUV ? "An" : "Aus";
  doc["LUER"] = bFAN ? "An" : "Aus";

  size_t lenght = serializeJson(doc, buf, sizeof(buf));

  //webSocket.sendTXT(0, buf, lenght);
  webSocket.broadcastTXT(buf, lenght);
  if(DEBUG)Serial.println((String)"broadcast: " + buf);
}
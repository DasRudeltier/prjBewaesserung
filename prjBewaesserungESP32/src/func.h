#define pSDA 21
#define pSCL 22
#define pFAN 26
#define pPUMP 25
#define pUV 14
#define pERDE 12

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

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Arduino.h>
#include <AiEsp32RotaryEncoder.h>
#include <customchars.h>

LiquidCrystal_I2C lcd(0x27,16,2);

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
  delay(300);
}

void INIT_FAN(){
  pinMode(pFAN, OUTPUT);
  if(DEBUG)digitalWrite(pFAN, HIGH);
  if(DEBUG)delay(1500);
  if(DEBUG)digitalWrite(pFAN, LOW);
  Serial.println("FAN INIT.");
  LCD_WRITE("FAN Ready!");
}

void INIT_PUMP(){
  pinMode(pPUMP, OUTPUT);
  if(DEBUG)digitalWrite(pPUMP, HIGH);
  if(DEBUG)delay(1500);
  if(DEBUG)digitalWrite(pPUMP, LOW);
  Serial.println("PUMP INIT.");
  LCD_WRITE("PUMP Ready!");
}

void INIT_LED(){
  pinMode(14, OUTPUT);
  if(DEBUG)digitalWrite(pUV, HIGH);
  if(DEBUG)delay(1500);
  if(DEBUG)analogWrite(pUV, LOW);
  Serial.println("UV/LED INIT.");
  LCD_WRITE("LED Ready!");
}

void INIT_TEST(){
  Serial.println("TEST INIT.");
  LCD_WRITE("TESTING!");
}

void FAN(bool anaus){ //EF - Lüfter ein/ausschalten | EIG - true/false
  if(anaus)digitalWrite(pFAN, HIGH);else{digitalWrite(pFAN,LOW);}
}

void TEMP_LESEN(){ //EF - Temperatursensor einlesen und speichern
  _TEMPERATUR = 0;
}

void DIRTHUMID_LESEN(){
  _ERDFEUCHT=analogRead(pERDE);
}

void HUMID_LESEN(){ //EF - Temperatursensor(Feuchtigkeit) einlesen und speichern
  _LUFTFEUCHT = 0;
}

void LICHT_LESEN(){
  _LICHT = 0;
}

void LCD_PREV(){

}

void INIT_SERIAL(){
  Serial.begin(9600);
  Serial.println("Serial INIT.");
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
  delay(3000);
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
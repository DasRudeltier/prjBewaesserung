#define pSDA 21
#define pSCL 22
#define pFAN 26
#define pPUMP 25
#define pUV 14
#define pERDE 12

float temp1 = 0.0;

float _TEMPERATUR = 0;
float _LUFTFEUCHT = 0;
float _ERDFEUCHT = 0;
float _LICHT = 0;

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Arduino.h>

String MENU[4][2] = 
{
    {"MENU1","TEST1"},
    {"MENU2","TEST2"},
    {"MENU3","TEST3"},
    {"MENU4","TEST4"},
};

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
  lcd.println("GUTEN TAG!");
  lcd.clear();
}

void INIT_FAN(){
    pinMode(pFAN, OUTPUT);
    digitalWrite(pFAN, HIGH);
    delay(1500);
    digitalWrite(pFAN, LOW);
}

void INIT_PUMP(){
    pinMode(pPUMP, OUTPUT);
    digitalWrite(pPUMP, HIGH);
    delay(1500);
    digitalWrite(pPUMP, LOW);
}

void INIT_LED(){
    pinMode(14, OUTPUT);
    digitalWrite(pUV, HIGH);
    delay(1500);
    analogWrite(pUV, LOW);
}

void INIT_TEST(){
  
}

void FAN(bool anaus){
if(anaus)digitalWrite(pFAN, HIGH);else{digitalWrite(pFAN,LOW);}
}

float TEMP_LESEN(){

return 0;
}

float HUMID_LESEN(){
  temp1=analogRead(pERDE);
  return temp1;
}

int LCD_NEXT_1 = 0;
void LCD_NEXT(){   
    lcd.home();
    lcd.clear();
    lcd.println(MENU[LCD_NEXT_1][1]);
    delay(1000);
    LCD_NEXT_1++;
    if(LCD_NEXT_1==4)LCD_NEXT_1=0; 
}

void LCD_PREV(){

}

void INIT_SERIAL(){
  Serial.begin(9600);
  Serial.println("Serial INIT.");
}

void UPDATE(){
  _ERDFEUCHT = HUMID_LESEN();
  _TEMPERATUR = TEMP_LESEN();
}

void LCD_WRITE(String EING){
  lcd.home();
  lcd.print("                ");
  lcd.home();
  lcd.print(EING);
  delay(300);
}

float HELLIGKEIT_LESEN(){

  return temp1;
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
    i=0;
    break;
  }
  LCD_WRITE(sBeschriftung);
  i++;
  delay(300);
}
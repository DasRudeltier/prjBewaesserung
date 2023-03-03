#define pSDA 21
#define pSCL 22
#define pFAN 19
#define pERDE 34

float temp1 = 0.0;

float _TEMPERATUR = 0;
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

void LCD_INIT(){
  lcd.init();
  lcd.backlight();
  lcd.clear();
}

void FAN_INIT(){
    pinMode(pFAN, OUTPUT);
    digitalWrite(pFAN,HIGH);
    delay(1500);
    digitalWrite(pFAN,LOW);
    delay(1500);
}

void FAN(bool anaus){
if(anaus)digitalWrite(pFAN, HIGH);else{digitalWrite(pFAN,LOW);}
}

float TEMP_LESEN(){

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
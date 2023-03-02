#define pSDA 21
#define pSCL 22
#define pFAN 19

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
}

void FAN(bool anaus){
if(anaus)digitalWrite(pFAN, HIGH);else{digitalWrite(pFAN,LOW);}
}

void TEMP_LESEN(){

}

void HUMID_LESEN(){

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
#include <Arduino.h>
#include <options.h>

void setup() {
  INIT_SERIAL();
  LCD_INIT();
  FAN_INIT();
}

void loop() {
  //LCD_TEST();
  //LCD_NEXT();
  FAN_INIT();
  
}


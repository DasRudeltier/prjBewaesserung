#include <Arduino.h>
#include <options.h>

void setup() {
  LCD_INIT();
  FAN_INIT();
}s

void loop() {
  //LCD_TEST();
  LCD_NEXT();
}


#include <Arduino.h>
#include <func.h>

void setup() {
  INIT_SERIAL();
    delay(500);
  INIT_FAN();
    delay(500);
  INIT_PUMP();
    delay(500);
  INIT_LED();
    delay(500);
  INIT_LCD();
}

void loop() {
  CYCLE_INFO();
  delay(2000);
}


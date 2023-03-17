#include <Arduino.h>
#include <func.h>

void setup() {
  INIT_LCD();
    delay(500);
  INIT_SERIAL();
    delay(500);
  INIT_FAN();
    delay(500);
  INIT_PUMP();
    delay(500);
  INIT_LED();
    delay(500);
  //INIT_RE();
}

void loop() {
  CYCLE_INFO();
  //rotary_loop();
}


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
  INIT_LIGHT();
    delay(500);
  INIT_TEMP();
    delay(500);
  //INIT_RE();
  INIT_WEB();
}

void loop() {
  CYCLE_INFO();
  LOOP_STEUERUNG();
  SERIAL_SEND();
  //rotary_loop();
  LOOP_WEB();
  LOOP_TIMER();
}
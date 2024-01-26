#include <Arduino.h>
#include "nLED.h"

#define LED_ALARM_PIN       8
#define LED_WARNING_PIN     9
#define LED_SUCCESS_PIN     10


void setup() {
  Serial.begin(9600);

  pinMode(LED_ALARM_PIN, OUTPUT);
  pinMode(LED_WARNING_PIN, OUTPUT);
  pinMode(LED_SUCCESS_PIN, OUTPUT);

}
bool a = 0;
void loop() {
  static Ledn ledAlarm(LED_ALARM_PIN);
  static Ledn ledWarning(LED_WARNING_PIN);
  static Ledn ledSuccess(LED_SUCCESS_PIN);

  Ledn sysLeds[3] = {Ledn(3)};
  
  sysLeds[0] = ledAlarm;
  sysLeds[1] = ledWarning;
  sysLeds[2] = ledSuccess;

  if (!a){
    for ( int i =0; i<3; i++)
      sysLeds[i].turn(ON);
  
    a=1;
  }
  
  
  delay(5000);

  for ( auto& sysLeds : sysLeds)
    sysLeds.turn(OFF);
  
}



#include "nLED.h"

void Ledn::turn(LedState_t order){
    digitalWrite(this->pinLed, order);
}

void Ledn::blink(unsigned long int timeOn, unsigned long int timeOff){
    uint8_t ledState = (uint8_t) digitalRead(this->pinLed);

    unsigned long int toggleTime = ledState == true ? timeOn : timeOff;

    if (millis() - this->startTimeForBlinking >= toggleTime){
        digitalWrite(this->pinLed, !ledState);
        this->startTimeForBlinking = millis();
    } 
}

void Ledn::blink(unsigned int timeBlink){
    uint8_t ledState = (uint8_t) digitalRead(this->pinLed);

    if (millis() - this->startTimeForBlinking >= timeBlink){
        digitalWrite(this->pinLed, !ledState);
        this->startTimeForBlinking = millis();
    }
}


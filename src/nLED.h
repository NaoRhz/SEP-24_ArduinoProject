#ifndef N_CLASS_LED
#define N_CLASS_LED
#include "Arduino.h"

enum LedState_t{OFF, ON};

class Ledn {
    private:
        uint8_t pinLed;
        unsigned long int startTimeForBlinking = 0;

    public:
        Ledn(uint8_t pinLed){
            this->pinLed = pinLed;
        }

        Ledn(){
        }

        void blink(unsigned long int timeOn, unsigned long int timeOff);
        void blink(unsigned int timeBlink);
        void turn(LedState_t order);
};

#endif /* N_CLASS_LED */
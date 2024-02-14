#ifndef _DELAY_H_
#define _DELAY_H_
#include <iostream>
#include <cmath>
#include "effect.h"

class Delay : public Effect
{
    public:
        Delay(float maxDelayTime, float delayTimeSamples, float feedback = 0.0f, float dryWet = 1.0f);
        ~Delay();

        float applyEffect(float input) override;
    private:
        float maxDelayTime;

        float delayTimeSamples;
        float feedback;

        float* delayBuffer;

        int readHeader = 0;
        int writeHeader = 0;

        void write(float input);
        float read();

        //default constructor
        Delay(){};
};

#endif

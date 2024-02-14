#ifndef _TREMOLO_H_
#define _TREMOLO_H_
#include <iostream>
#include <cmath>
#include "sine.h"
#include "effect.h"

class Tremolo : public Effect
{
    public:
        Tremolo(float modDepth, float freq, float dryWet = 1.0f);
        ~Tremolo();

        float applyEffect(float input) override;
    private:
        Sine* sine;
        float modDepth;
        float freq;

        float currentValue;
        float currentDepth;

        //default constructor
        Tremolo(){};
};

#endif

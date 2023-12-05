#ifndef _OSCILLATOR_H_
#define _OSCILLATOR_H_
#include <iostream>

class Oscillator{
    public:
        Oscillator(float f, float sr);
        ~Oscillator();
    
        virtual float getSample();
        void setFrequency(float f);
        float getFrequency();

        //TODO make the sounds

    protected:    
        float frequency;
        float sample;
        float phaseStep;
        float phase;
        float sampleRate;
};

#endif
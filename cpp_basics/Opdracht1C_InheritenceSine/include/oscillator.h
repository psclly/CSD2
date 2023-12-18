#ifndef _OSCILLATOR_H_
#define _OSCILLATOR_H_
#include <iostream>

class Oscillator{
    public:
        Oscillator(float f, float sr);
        virtual ~Oscillator();
    
        float getSample();
        void setFrequency(float f);
        void setSamplerate(int r);
        float getFrequency();
        void tick();
        float getPhase();

        //TODO make the sounds

        virtual void calculate() = 0;



    protected:    
        float frequency;
        float sample;
        float phaseStep;
        float phase;
        float sampleRate;
        float amplitude;
};

#endif
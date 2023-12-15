#ifndef _SYNTH_H_
#define _SYNTH_H_
#include "../include/oscillator.h"
#include "../include/sine.h"
#include "../include/saw.h"
#include "../include/square.h"

class Synthesizer{
    public:
        Synthesizer(int type, float freq, float sr);
        ~Synthesizer();
        float getSample();   
        void tick();
        void setSamplerate(float sr);
        void setFrequency(float f);

    private:  
        Oscillator* synthWave = nullptr;
};

#endif
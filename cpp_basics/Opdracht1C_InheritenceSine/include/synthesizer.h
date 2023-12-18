#ifndef _SYNTH_H_
#define _SYNTH_H_
#include "../include/oscillator.h"
#include "../include/sine.h"
#include "../include/saw.h"
#include "../include/square.h"

class Synthesizer{
    public:
        Synthesizer(float freq, float sr, int type);
        ~Synthesizer();
        float getSample();   
        void tick();
        void setSamplerate(float sr);
        void setFrequency(float f);
        void nextNote();


    private:  
        int currentNoteIndex;
        int melody[5];
        Sine sineWave;
        Square squareWave;
        Saw sawWave;
        Oscillator* pointWave;   
};

#endif
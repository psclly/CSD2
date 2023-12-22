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
        void setType(int t);


    private:  
        int waveType;
        int currentNoteIndex;
        int melody[5];
        int frameCounter;

        Oscillator* pointWave;
};

#endif
#include <iostream>
#include "../include/synthesizer.h"
#include <cmath>

//function stolen from Ciska
float mtof(float midi){
    return 440.0 * pow(2.0, (midi - 69.0f)/12.0f);
}

Synthesizer::Synthesizer(float freq, float sr, int type)
{
    switch(type){
        case 0: pointWave = new Sine(freq, sr); break;
        case 1: pointWave = new Square(freq, sr); break;
        case 2: pointWave = new Saw(freq, sr); break;
        default: pointWave = new Sine(freq,sr); break;
    }
    
    waveType = type;
    int melody[5];
    
    for(int i = 0; i < 5; ++i){
        melody[i] = 60 + i * 2;
    }

    setFrequency(mtof(melody[currentNoteIndex]));
};

Synthesizer::~Synthesizer(){
    pointWave = nullptr;
    delete pointWave;
}

float Synthesizer::getSample(){
    return pointWave->getSample();
}

void Synthesizer::tick(){
    pointWave->tick();
    frameCounter++;
    if(frameCounter > 1000){
        nextNote();
    }
}

void Synthesizer::setSamplerate(float sr){
    pointWave->setSamplerate(sr);
}

void Synthesizer::setFrequency(float f){
    pointWave->setFrequency(f);
}

void Synthesizer::nextNote(){
    currentNoteIndex += 1;
    if(currentNoteIndex > 4){currentNoteIndex = 0;}
    setFrequency(mtof(melody[currentNoteIndex]));
}

void Synthesizer::setType(int t){
    waveType = t;
}
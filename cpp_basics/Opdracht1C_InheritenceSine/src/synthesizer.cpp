#include <iostream>
#include "../include/synthesizer.h"
#include <cmath>

//function stolen from Ciska
float mtof(float midi){
    return 440.0 * pow(2.0, (midi - 69.0f)/12.0f);
}

Synthesizer::Synthesizer(int type, float freq, float sr){
    int melody[5];
    for(int i = 0; i < 5; ++i){
        melody[i] = 60 + i * 2;
    }

    setFrequency(mtof(melody[currentNoteIndex]));

    switch(type){
        case 0:
            synthWave = new Sine(freq, sr);
            break;
        case 1:
            synthWave = new Square(freq, sr);
            break;
        case 2:
            synthWave = new Saw(freq, sr);
            break;
        default:
            std::cout << "Invalid arguments for Synthesizer";
            break;
    }
};

Synthesizer::~Synthesizer(){}

float Synthesizer::getSample(){
    return synthWave->getSample();
};

void Synthesizer::tick(){
    synthWave->tick();
}

void Synthesizer::setSamplerate(float sr){
    synthWave->setSamplerate(sr);
}

void Synthesizer::setFrequency(float f){
    synthWave->setFrequency(f);
}

void Synthesizer::nextNote(){
    currentNoteIndex += 1;
    setFrequency(mtof(melody[currentNoteIndex]));
}

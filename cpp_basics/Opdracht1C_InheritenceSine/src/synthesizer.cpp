#include <iostream>
#include "../include/synthesizer.h"
#include <cmath>

//function stolen from Ciska
float mtof(float midi){
    return 440.0 * pow(2.0, (midi - 69.0f)/12.0f);
}

Synthesizer::Synthesizer(float freq, float sr, int type){
    std::cout << "print A";     
    int melody[5];
    Sine sineWave = Sine(freq, sr);
    Square squareWave = Square(freq, sr);
    Saw sawWave = Saw(freq,sr);

    
    for(int i = 0; i < 5; ++i){
        melody[i] = 60 + i * 2;
    }

    setFrequency(mtof(melody[currentNoteIndex]));

    switch(type){
        case 0:
            pointWave = &sineWave;
            break;
        case 1:
            pointWave = &squareWave;
            break;
        case 2:
            pointWave = &sawWave;
            break;
        default:
            std::cout << "Invalid arguments for Synthesizer";
            break;
    }
};

Synthesizer::~Synthesizer(){
    delete pointWave;
}

float Synthesizer::getSample(){
    return pointWave->getSample();
};

void Synthesizer::tick(){
    pointWave->tick();
}

void Synthesizer::setSamplerate(float sr){
    pointWave->setSamplerate(sr);
}

void Synthesizer::setFrequency(float f){
    pointWave->setFrequency(f);
}

void Synthesizer::nextNote(){
    currentNoteIndex += 1;
    setFrequency(mtof(melody[currentNoteIndex]));
}

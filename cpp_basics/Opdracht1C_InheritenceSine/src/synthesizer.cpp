#include <iostream>
#include "../include/synthesizer.h"
#include <cmath>

Synthesizer::Synthesizer(int type, float freq, float sr){
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
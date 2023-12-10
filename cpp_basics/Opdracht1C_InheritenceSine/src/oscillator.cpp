#include <iostream>
#include "../include/oscillator.h"
#include <cmath>

Oscillator::Oscillator(float f, float sr){
    this->frequency = f;
    sample = 0;
    sampleRate = sr;
    amplitude = 1;

    phaseStep = this->frequency / sampleRate;
};

Oscillator::~Oscillator(){
    std::cout << "Deconstructed Sine";
};

float Oscillator::getSample(){
    return sample;
};

void Oscillator::setFrequency(float f){
    this->frequency = f;
    phaseStep = this->frequency / sampleRate;
}

float Oscillator::getFrequency(){
    return this->frequency;
}

void Oscillator::tick(){
    calculate();
    phase += phaseStep;
    if(phase > 1){
        phase = 0;
    }
};

float Oscillator::getPhase(){
    return phase;
}
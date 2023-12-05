#include <iostream>
#include "../include/oscillator.h"
#include <cmath>

Oscillator::Oscillator(float f, float sr){
    this->frequency = f;
    std::cout << "Constructed Sine with frequency " << this->frequency << std::endl;
    sample = 0;
    sampleRate = sr;

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
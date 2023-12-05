#include <iostream>
#include "../include/saw.h"
#include <cmath>

Saw::Saw(float f, float sr) : Oscillator(f, sr){
    std::cout << "Created Saw Oscillator with frequency " << f << std::endl;
};

void Saw::calculate(){
    sample = (phase * 2 - 1) * amplitude;
}
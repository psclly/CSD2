#include <iostream>
#include "../include/sine.h"
#include <cmath>

Sine::Sine(float f, float sr) : Oscillator(f, sr){
    std::cout << "Created Sine Oscillator with parameters " << f << sr << std::endl;
};

void Sine::tick(){
    phase += phaseStep;
    sample = sin(2 * M_PI * phase);
};


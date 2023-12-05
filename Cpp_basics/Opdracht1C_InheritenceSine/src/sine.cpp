#include <iostream>
#include "../include/sine.h"
#include <cmath>

Sine::Sine(float f, float sr) : Oscillator(f, sr){
    std::cout << "Created Sine Oscillator with frequency " << f << std::endl;
};

void Sine::calculate(){
    sample = sin(2 * M_PI * phase);
}

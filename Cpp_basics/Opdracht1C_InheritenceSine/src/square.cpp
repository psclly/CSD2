#include <iostream>
#include "../include/square.h"
#include <cmath>

Square::Square(float f, float sr) : Oscillator(f, sr){
    std::cout << "Created Square Oscillator with parameters " << f << sr << std::endl;
};

void Square::tick(){
    phase += phaseStep;
    sample = sin(2 * M_PI * phase);
};

float Square::getSample(){
    if (sample > 0){
        return 1;
    } else {
        return -1;
    }
};
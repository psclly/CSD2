#include <iostream>
#include "../include/square.h"
#include <cmath>

Square::Square(float f, float sr) : Oscillator(f, sr){
    std::cout << "Created Square Oscillator with frequency " << f << std::endl;
};

void Square::calculate(){
    sample = sin(2 * M_PI * phase);
}
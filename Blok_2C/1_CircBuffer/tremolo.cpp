#include "sine.h"
#include "effect.h"
#include "tremolo.h"

Tremolo::Tremolo(float modDepth, float freq, float dryWet) : Effect(dryWet){
    this->modDepth = modDepth;
    this->freq = freq;

    sine = new Sine(this->freq);

}

Tremolo::~Tremolo(){
    delete sine;
    sine = nullptr;
}

float Tremolo::applyEffect(float input){
    float effectValue;
    sine->tick();
    //scale the sine sample from -1-1 to 0-1
    currentValue = (sine->getSample() + 1) * 0.5;
    //scale the sine sample from 0-1 to modDepth-1
    effectValue = modDepth * currentValue + (1-modDepth);

    //apply the effect on the input and return it
    //std::cout << "Input: " << input << " multiplied by: " << effectValue << std::endl;
    return effectValue * input;
}
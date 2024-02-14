#include "effect.h"

Effect::Effect(float dryWet){
    std::cout << "Constructor: Effect" << std::endl;
    setDryWet(dryWet);
}

Effect::~Effect(){
    std::cout << "Destructor: Effect" << std::endl;
}

void Effect::setDryWet(float dryWet){
    wet = dryWet;
    dry = 1.0f - dryWet;
    this->dryWet = dryWet;
}

float Effect::getDryWet(){
    return dryWet;
}

float Effect::processFrame(float input){
    float output = applyEffect(input);

    //calculate dry and wet
    float dryOutput = input * dry;
    float wetOutput = output * wet;

    output = wetOutput + dryOutput;


    //todo apply dry wet

    return output;
}
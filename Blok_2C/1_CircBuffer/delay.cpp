#include "effect.h"
#include "delay.h"

Delay::Delay(float maxDelayTime, float delayTimeSamples, float feedback, float dryWet) : Effect(dryWet){
    std::cout << "Constructor: Delay" << std::endl;
    
    float* delayBuffer = new float[maxDelayTime];

    this->maxDelayTime = maxDelayTime;
    this->delayTimeSamples = delayTimeSamples;
    this->feedback = feedback;

    std::cout << "Preparing array" << std::endl;

    for(int i = 0; i < delayTimeSamples; i++){
        write(0.0f);
    }
}

Delay::~Delay(){
    delete delayBuffer;
    delayBuffer = nullptr;
}

float Delay::applyEffect(float input){
    std::cout << "Applying effect delay" << std::endl;
    write(input);
    return read();
}

void Delay::write(float input){
    std::cout << "Writing " << input << " @ " << writeHeader << std::endl;
    delayBuffer[writeHeader] = input;
    std::cout << "Checking wrap.. " << std::endl;
    writeHeader++;
    if(writeHeader >= maxDelayTime){
        writeHeader -= maxDelayTime;
    }
}

float Delay::read(){
    std::cout << "Reading @ " << readHeader << std::endl;
    return delayBuffer[readHeader++];
    if(readHeader >= maxDelayTime){
        readHeader -= maxDelayTime;
    }
}
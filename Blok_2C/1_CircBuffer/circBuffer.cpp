#include "circBuffer.h"
#include <iostream>

CircBuffer::CircBuffer(){
    std::cout << "Constructor: Circular Buffer" << std::endl;
    delayTime = 40000;
    readHeader = 0;
    writeHeader = 0;
    prepare();
}

CircBuffer::~CircBuffer(){
    std::cout << "Destructor: Circular Buffer" << std::endl;
}

void CircBuffer::prepare(){
    //Fill up the array with 0s so not to read null
    for (int i = 0; i < delayTime; i++){
        write(0);
    }
    std::cout << "preparation done" << std::endl;
}

void CircBuffer::write(float sample){
    //std::cout << "Writing at " << writeHeader << std::endl;
    buffer[writeHeader] = sample;
    writeHeader++;

    //once header reached end of array, reset
    if(writeHeader >= SIZE){
        writeHeader -= SIZE;
        std::cout << "1000 reached" << std::endl;
    }
}

float CircBuffer::read(){
    //std::cout << "Reading at " << readHeader << std::endl;
    float output = buffer[readHeader];
    readHeader++;

    //once header reached end of array, reset
    if(readHeader >= SIZE){
        readHeader -= SIZE;
        std::cout << "1000 reached" << std::endl;
    }

    return output;
}
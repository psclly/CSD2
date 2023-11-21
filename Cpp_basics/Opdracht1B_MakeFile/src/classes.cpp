#include <iostream>
#include "../include/classes.h"

Instrument::Instrument(const int index, const std::string name, const std::string sound){
    this->index = index;
    this->name = name;
    this->sound = sound;
}

void Instrument::playSound(){
    std::cout << this->index << " " << this->name << " do be soundin' like " << this->sound << std::endl;
}

void Instrument::roll(int amount){
    std::cout << "Rolling on the " << this->name << " sounds like: " << std::endl;
    for(int i = 0; i < amount; i++){
        std::cout << this->sound << std::endl;
    }
}
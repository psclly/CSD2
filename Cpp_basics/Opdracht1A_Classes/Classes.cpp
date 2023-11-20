    #include <iostream>
#include "Classes.h"

Instrument::Instrument(const int index, const std::string name, const std::string sound){
    instrumentIndex = index;
    instrumentName = name;
    instrumentSound = sound;
}

void Instrument::playSound(){
    std::cout << instrumentIndex << " " << instrumentName << " do be soundin' like " << instrumentSound << std::endl;
}
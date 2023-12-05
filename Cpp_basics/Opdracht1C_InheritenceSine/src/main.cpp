#include <iostream>
#include "../include/oscillator.h"
#include "../include/sine.h"
#include "../include/square.h"
#include <fstream>
#include <cstdio>

int main(){
    const float samplerate = 44100;
    Square wave(3, samplerate);

    std::remove("output.csv");
    std::ofstream csvFile("output.csv");
    csvFile << "Time,Sample" << std::endl;

    for(int i = 0; i<=samplerate; i++){
        //std::cout << i << " => " << wave.getSample() << std::endl;
        csvFile << i << ", " << wave.getSample() << std::endl;

        wave.tick();
    };

    return 0;
}
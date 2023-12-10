#include <iostream>
#include "../include/oscillator.h"
#include "../include/sine.h"
#include "../include/square.h"
#include "../include/saw.h"
#include <fstream>
#include <cstdio>

int main(){
    const float samplerate = 44100;
    Sine wave(20, samplerate);
    //Square wave2(20, samplerate);

    std::remove("output.csv");
    std::ofstream csvFile("output.csv");
    csvFile << "Time,Sample,Phase" << std::endl;

    for(int i = 0; i<=samplerate; i++){
        wave.tick();
        //wave2.tick();
        //std::cout << i << " => " << wave.getSample() << std::endl;
        csvFile << i << ", " << wave.getSample() << ", " << wave.getPhase() <<std::endl;
        //csvFile << i << ", " << wave2.getSample() << ", " << wave2.getPhase() <<std::endl;
    };

    return 0;
}
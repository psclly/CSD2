#include <iostream>
#include "../include/oscillator.h"
#include "../include/sine.h"
#include "../include/square.h"
#include <fstream>
#include <cstdio>

int main(){
    const float samplerate = 44100;
    Square u(2, samplerate);

    std::remove("output.csv");
    std::ofstream csvFile("output.csv");
    csvFile << "Time,Sample" << std::endl;




    for(int i = 0; i<=samplerate; i++){
        std::cout << i << " => " << u.getSample() << std::endl;
        csvFile << i << ", " << u.getSample() << std::endl;

        u.tick();
        


    };

    return 0;
}
#include <iostream>
#include "../include/oscillator.h"
#include "../include/sine.h"
#include "../include/square.h"
#include "../include/saw.h"
#include "../include/synthesizer.h"
#include <fstream>
#include <cstdio>
#include "jack_module.h"
#include <math.h>



class CustomCallback : public AudioCallback {
    private:
        int voices = 4;
        float sample = 0;
        float samplerate = 44100;

        Synthesizer wave = Synthesizer(0, 440, 44100);

    
    public:
        void changeFrequency(int f){
            wave.setFrequency(f);
        }

        void nextNote(){
            wave.nextNote();
        }
        
        void prepare(int rate) override {
            samplerate = (float) rate;
            wave.setSamplerate(samplerate);
            std::cout << "\nsamplerate: " << samplerate << "\n";
        }

        void process(AudioBuffer buffer) override {
            for (int i = 0; i < buffer.numFrames; ++i) {
                buffer.outputChannels[0][i] = sample;
            }
        }
};

int main(){
    std::cout << "This doesnt work?";
    auto callback = CustomCallback {};
    std::cout << "success!";
    auto jackModule = JackModule { callback };

    jackModule.init(0, 1);

    std::remove("output.csv");
    std::ofstream csvFile("output.csv");
    csvFile << "Time,Sample,Phase" << std::endl;
    bool running = true;
    
    while (running) {
        int newFrequency = 0;
        switch (std::cin.get()) {
            case 'q':
                running = false;
                break;
            case 'f':
                std::cout << "Enter Frequency: ";
                std::cin >> newFrequency;
                callback.changeFrequency(newFrequency);
                break;
            case 'n':
                std::cout << "Next Note in Melody";
                callback.nextNote();  
                break;
            default:
                break;
      }
    }

    return 0;
}
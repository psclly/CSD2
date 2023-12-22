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

        Synthesizer waveI = Synthesizer(440, 44100, 0);
        Synthesizer waveII = Synthesizer(220, 44100, 1);
        Synthesizer waveIII = Synthesizer(880, 44100, 2);

        std::ofstream csvFile;
        
        


    public:
        void changeFrequency(int f){
            waveI.setFrequency(f);
            waveII.setFrequency(f);
        }

        void nextNote(){
            waveI.nextNote();
            waveII.nextNote();
        }

        void setType(int t){
            waveI.setType(t);
            waveII.setType(t);
        }
        
        void prepare(int rate) override {
            std::remove("output.csv");
            std::ofstream csvFile("output.csv");
            csvFile << "Time,Sample,Phase" << std::endl;

            samplerate = (float) rate;
            waveI.setSamplerate(samplerate);
            waveII.setSamplerate(samplerate);
            std::cout << "\nsamplerate: " << samplerate << "\n";
        }

        void process(AudioBuffer buffer) override {
            for (int i = 0; i < buffer.numFrames; ++i) {
                csvFile << waveI.getSample();
                buffer.outputChannels[0][i] = waveI.getSample() + waveII.getSample();
                waveI.tick();
                waveI.tick();
                std::cout << buffer.outputChannels[0][i] << std::endl;
            }
        }
};

int main(){
    int newType;
    std::cout << "-- This doesnt work?" << std::endl;
    auto callback = CustomCallback {};
    std::cout << "success!";
    auto jackModule = JackModule { callback };

    jackModule.init(0, 1);


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
                std::cout << "Next Note in Melody\n";
                callback.nextNote();  
                break;
            case 't':
                std::cout << "Change Type: ";
                std::cin >> newType;
                callback.setType(newType);
            default:
                break;
      }
    }

    return 0;
}
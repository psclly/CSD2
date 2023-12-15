#include <iostream>
#include "../include/oscillator.h"
#include "../include/sine.h"
#include "../include/square.h"
#include "../include/saw.h"
#include "../include/synthesizer.h"
#include <fstream>
#include <cstdio>
#include "jack_module.h"

class CustomCallback : public AudioCallback {
public:
    void prepare(int rate) override {
        samplerate = (float) rate;
        wave1.setSamplerate(samplerate);
        std::cout << "\nsamplerate: " << samplerate << "\n";
    }

    void process(AudioBuffer buffer) override {
        for (int i = 0; i < buffer.numFrames; ++i) {
        // write sample to buffer at channel 0, amp = 0.25
        buffer.outputChannels[0][i] = wave1.getSample();

        wave1.tick();
        }
    }

    private:
        float samplerate = 44100;
        Synthesizer wave1 = Synthesizer(0, 440, 44100);

    public:
        void changeFrequency(int f){
            wave1.setFrequency(f);
    }
};

int main(){
    auto callback = CustomCallback {};
    auto jackModule = JackModule { callback };

    jackModule.init(0, 1);

    std::remove("output.csv");
    std::ofstream csvFile("output.csv");
    csvFile << "Time,Sample,Phase" << std::endl;

    bool running = true;
    
    while (running) {
        switch (std::cin.get()) {
            case 'q':
                running = false;
                break;
            case 'f':
                std::cout << "Enter Frequency: ";
                int newFrequency = 0;
                std::cin >> newFrequency;
                callback.changeFrequency(newFrequency);
                break;
            
      }
  }

    return 0;
}
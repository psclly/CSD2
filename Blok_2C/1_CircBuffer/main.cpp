//
// Created by Dean't on 02/12/2023.
//
#include "sine.h"
#include "circBuffer.h"
#include "effect.h"
#include "tremolo.h"
#include "writeToFile.h"
#include "delay.h"

#include "audiocomponent.h"
#include <iostream>


struct CustomCallback : AudioCallback {
    explicit CustomCallback (double sampleRate) : AudioCallback(sampleRate) {
        //PREPARE STUFF HERE (Add sines, oscillators what not)
        //Example:
        //sine = new Sine(440, sampleRate)

        sine = new Sine(440, sampleRate);
        tremolo = new Tremolo(1, 10, 1); 
        delay = new Delay(sampleRate, 10000, 0, 1);

        fileWriter = new WriteToFile("output.csv", true);
        writeIndex = 0;
        fileWriter->write(std::string("Time,Sample\n"));
    }

    ~CustomCallback() override {
        //DESTROY STUFF HERE (Deconstructors, deletes what not)
        //Example:
            //delete sine;
            //sine = nullptr;
        delete sine;
        sine = nullptr;
        delete tremolo;
        tremolo = nullptr;
        delete fileWriter;
        fileWriter = nullptr;
        delete delay;
        delay = nullptr;
    }

    void prepare (int sampleRate) override {
    }

    void process (AudioBuffer buffer) override {
        auto [inputChannels, outputChannels, numInputChannels, numOutputChannels, numFrames] = buffer;

        for (int channel = 0u; channel < numOutputChannels; ++channel) {
            for (int sample = 0u; sample < numFrames; ++sample) {
               //PROCESS LOOP
                //outputChannels[channel][sample] = inputChannels[0][sample];
                sine->tick();

                std::cout << "Entering " << sine->getSample();
                samplePlusEffects = delay->processFrame(tremolo->processFrame(sine->getSample()));
                std::cout << "Received " << samplePlusEffects;
                outputChannels[channel][sample] = samplePlusEffects;

                /*fileWriter->write(std::to_string(writeIndex) + "," 
                    + std::to_string(samplePlusEffects) + "\n");

                writeIndex++;*/
            }
        }
    }

    private:
        Sine* sine;
        Effect* tremolo;
        float samplePlusEffects;
        WriteToFile* fileWriter;
        int writeIndex;
        Effect* delay;
        
};




int main() {
    ScopedMessageThreadEnabler scopedMessageThreadEnabler;
    CustomCallback audioSource (44100);



    JUCEModule juceModule (audioSource);
    juceModule.init(1,1);


    std::cout << "Press q Enter to quit..." << std::endl;
    bool running = true;
    while (running) {
        switch (std::cin.get()) {
            case 'q':
                running = false;
                break;
        }
    }


    return 0;
}

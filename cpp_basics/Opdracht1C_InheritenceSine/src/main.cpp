#include <iostream>
#include "../include/oscillator.h"
#include "../include/sine.h"
#include "../include/square.h"
#include "../include/saw.h"
#include <fstream>
#include <cstdio>
#include "jack_module.h"

class CustomCallback : public AudioCallback {
public:
  void prepare(int rate) override {
    samplerate = (float) rate;
    wave1.setSamplerate(samplerate);
    wave2.setSamplerate(samplerate);
    wave3.setSamplerate(samplerate);
    std::cout << "\nsamplerate: " << samplerate << "\n";
  }

  void process(AudioBuffer buffer) override {
    for (int i = 0; i < buffer.numFrames; ++i) {
      // write sample to buffer at channel 0, amp = 0.25
      buffer.outputChannels[0][i] = wave1.getSample() + wave2.getSample() + wave3.getSample();
      
      wave1.tick();
      wave2.tick();
      wave3.tick();
    }
  }

  private:
    float samplerate = 44100;
    Sine wave1 = Sine(440, samplerate);
    Square wave2 = Square(660, samplerate);
    Saw wave3 = Saw(220, samplerate);
};

int main(){
    auto callback = CustomCallback {};
    auto jackModule = JackModule { callback };

    jackModule.init (0, 1);


    const float samplerate = 44100;

    std::remove("output.csv");
    std::ofstream csvFile("output.csv");
    csvFile << "Time,Sample,Phase" << std::endl;

    bool running = true;
    while (running) {
      switch (std::cin.get()) {
          case 'q':
              running = false;
      }
  }

    return 0;
}
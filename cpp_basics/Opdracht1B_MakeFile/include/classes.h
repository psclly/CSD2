#include <iostream>

class Instrument{
    private:
        int index;

        std::string name;
        std::string sound;
        std::string amount;

    public:

        //Constructor
        Instrument(const int index, const std::string name, const std::string sound);

        //Member functions
        void playSound();

        void roll(int amount);
};
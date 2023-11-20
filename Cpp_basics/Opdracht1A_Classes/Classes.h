#include <iostream>

class Instrument{
    private:
        int instrumentIndex;
        std::string instrumentName;
        std::string instrumentSound;

    public:
        //Constructor
        Instrument(const int index, const std::string name, const std::string sound);

        //Member functions
        void playSound();
};

hi
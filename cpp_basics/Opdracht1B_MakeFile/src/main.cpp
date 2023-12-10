#include <iostream>
#include "../include/classes.h"

int main(){
    Instrument timpani(0, "timpani", "bonk");
    Instrument voice(1, "voice", "AAAAAAAAAAA");
    Instrument viola(2, "viola", "ReEEeeeeEEEee");

    timpani.playSound();
    voice.playSound();
    viola.playSound();
   
    std::cout << "rolling!";
    timpani.roll(5);

    return 0;
}
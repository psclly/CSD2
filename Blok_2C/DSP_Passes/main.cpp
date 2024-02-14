#include <iostream>
#include <math.h>
#include <fstream>
#include "writeToFile.h"
#include <string>
#define PI 3.14159265

float sine(float f, int sr, int n){
    return sin((2*PI*f*n)/sr);
}

float filt(float x){
    static float prevx = 0;
    float y = 0.5*x + 0.5*prevx;
    prevx = x;
    return y;
}



int main(){
    int size;
    float freq;

    std::cin >> size;
    std::cin >> freq;

    int sr = 48000;

    float* samples = new float[size];
    samples[0] = 0;

    WriteToFile fileWriter("output.csv", true);
    fileWriter.write(std::string("Time,Sample\n"));

    for(int n = 0; n < size; n++){
        fileWriter.write(std::to_string(n) + ",");
        //fileWriter.write(std::to_string(filt(sine(freq, sr, n))) + "\n");
        fileWriter.write(std::to_string(filt(n)) + "\n");

    }


   
   
    delete[] samples;  
    return 0;
}


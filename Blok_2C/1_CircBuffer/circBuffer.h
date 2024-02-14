#ifndef _CIRC_H_
#define _CIRC_H_
#define SIZE 44100
class CircBuffer{
    public:
        CircBuffer();
        ~CircBuffer();


        void write(float sample);
        float read();
        void prepare();


    private:
        float buffer[SIZE];

        int readHeader;
        int writeHeader;
        int delayTime;
};


#endif
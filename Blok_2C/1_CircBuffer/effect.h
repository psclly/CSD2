#ifndef _EFFECT_H_
#define _EFFECT_H_
#include <iostream>

class Effect{
    public:
        Effect(float dryWet);
        virtual ~Effect();
        void setDryWet(float dryWet);
        float getDryWet();
        float processFrame(float sample);

    private:
        float dryWet;
        float wetDry;
        float dry;
        float wet;



    protected:
        Effect(){};
        float virtual applyEffect(float sample) = 0;
};

#endif
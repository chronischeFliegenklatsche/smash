#ifndef _TIMED_TONE_HPP
#define _TIMED_TONE_HPP

#include "Tone.hpp"

namespace smash {

    struct TimedTone;
    
    struct TimedTone : public Tone{
        
        float startTime;
        TimedTone();
        TimedTone(float frequency, float duration, float startTime);

    };
}   

#endif
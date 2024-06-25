#ifndef _TONE_HPP
#define _TONE_HPP

namespace smash {

    struct Tone;

    struct Tone {
 
        float frequency; /**< The frequency of the tone. */
        float duration; /**< The duration of the tone. */
        Tone();
        Tone(float frequency, float duration);
    };
} 

#endif
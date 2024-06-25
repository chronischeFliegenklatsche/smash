#ifndef _TONE_HPP
#define _TONE_HPP

namespace smash {

    struct Tone;

    struct Tone {
 
        Tone();
        Tone(float frequency, float duration);

        float frequency; /**< The frequency of the tone. */
        float duration; /**< The duration of the tone. */
        
    };
} 

#endif
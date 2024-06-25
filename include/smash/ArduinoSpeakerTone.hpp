#ifndef _ARDUINO_SPEAKER_TONE_HPP
#define _ARDUINO_SPEAKER_TONE_HPP

#include "Tone.hpp"

namespace smash {

    struct ArduinoSpeakerTone;

    struct ArduinoSpeakerTone : public Tone {
        int preferredOutput;

        ArduinoSpeakerTone();

        ArduinoSpeakerTone(float frequency, float duration, int preferredOutput);
            
    };
}

#endif
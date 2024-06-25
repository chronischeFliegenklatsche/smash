
#ifndef _SPEAKER_TONE_HPP
#define _SPEAKER_TONE_HPP

#include "Tone.hpp"

namespace smash {

    struct SpeakerTone;

    struct SpeakerTone : public Tone {
        int preferredOutput;

        SpeakerTone();

        SpeakerTone(float frequency, float duration, int preferredOutput);
            
    };
}

#endif
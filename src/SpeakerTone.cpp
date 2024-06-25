
#include <smash.h>

namespace smash {
    
    SpeakerTone::SpeakerTone(float frequency, float duration, int preferredOutput) : Tone(frequency, duration), preferredOutput(preferredOutput) {
    }
}
#ifdef ARDUIO
#include <smash.h>

namespace smash {
    
    ArduinoSpeakerTone::ArduinoSpeakerTone(float frequency, float duration, int preferredOutput) : Tone(frequency, duration), preferredOutput(preferredOutput) {
    }
}
#endif
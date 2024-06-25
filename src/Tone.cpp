#ifdef _TONE_HPP
#include <smash.h>

namespace smash {
    Tone::Tone(){
    }
                                // member intializer, überspringt standard initialisierung
    Tone::Tone(float frequency, float duration) : frequency(frequency), duration(duration) {
    }
}
#endif
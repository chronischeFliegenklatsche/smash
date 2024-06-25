#ifdef _TIMED_TONE_HPP
#include <smash.h>

namespace smash {
    TimedTone::TimedTone(){
    }

    TimedTone::TimedTone(float frequency, float duration, float startTime) : Tone(frequency, duration), startTime(startTime) {
    }
}
#endif
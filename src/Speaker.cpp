
#include <smash.h>

namespace smash {

    Speaker::Speaker(int pin) : _pin(pin) {
    }

    void Speaker::play(float frequency) {
#ifdef ARDUINO
        tone(_pin, frequency);
#endif
        _endTime = _SPEAKER_ENDLESS;

    }

    void Speaker::play(Tone inputTone) {
#ifdef ARDUINO
        tone(_pin, inputTone.frequency, inputTone.duration);
        _endTime = inputTone.duration + millis();
#endif
    }

    bool Speaker::isPlaying() {
        if(_endTime == _SPEAKER_MUTE ) {
            return false;
        } else if (_endTime == _SPEAKER_ENDLESS) {
            return true;
        } else {
#ifdef ARDUINO
            return _endTime > millis(); // falls Stoppzeitpunkt kleiner ist als gesamte jetzige vergange Zeit
#endif
        }
    }

    void Speaker::interrupt() {
#ifdef ARDUINO
        noTone(_pin);
#endif
        _endTime = _SPEAKER_MUTE;
    }
}
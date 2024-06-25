#ifdef _ARDUINO_SPEAKER_HPP
#include <smash.h>

namespace smash {

    Speaker::Speaker(int pin) : _pin(pin) {
    }

    void Speaker::play(float frequency) {
        tone(_pin, frequency);
        _endTime = _SPEAKER_ENDLESS;

    }

    void Speaker::play(Tone inputTone) {
        tone(_pin, inputTone.frequency, inputTone.duration);
        _endTime = inputTone.duration + millis();
    }

    bool Speaker::isPlaying() {
        if(_endTime == _SPEAKER_MUTE ) {
            return false;
        } else if (_endTime == _SPEAKER_ENDLESS) {
            return true;
        } else {
            return _endTime > millis(); // falls Stoppzeitpunkt kleiner ist als gesamte jetzige vergange Zeit
        }
    }

    void Speaker::interrupt() {
        noTone(_pin);
        _endTime = _SPEAKER_MUTE;
    }
}
#endif
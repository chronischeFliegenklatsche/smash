#ifndef _ARDUINO_SPEAKER_HPP
#define _ARDUINO_SPEAKER_HPP

#include "Tone.hpp"
#include "ArduinoSpeakerTone.hpp"

namespace smash {

    /**
     * @brief Represents a speaker that can play tones.
     */
    class Speaker;

    /**
     * @brief Represents a speaker that can play tones.
     */
    class Speaker {
#define _SPEAKER_MUTE -2
#define _SPEAKER_ENDLESS -1
        int _pin;
        float _endTime = _SPEAKER_MUTE;
        
        public:
            /**
             * @brief Constructs a Speaker object with the specified pin.
             * 
             * @param pin The pin number to which the speaker is connected.
             */
            Speaker(int pin);

            /**
             * @brief Plays a tone with the specified frequency.
             * 
             * @param frequency The frequency of the tone to be played.
             */
            void play(float frequency);

            /**
             * @brief Plays a tone.
             * 
             * @param tone The tone to be played.
             */
            void play(Tone tone);

            /**
             * @brief Checks if the speaker is currently playing a tone.
             * 
             * @return true if the speaker is playing a tone, false otherwise.
             */
            bool isPlaying();

            /**
             * @brief Interrupts the currently playing tone.
             */
            void interrupt();
    };
}

#endif
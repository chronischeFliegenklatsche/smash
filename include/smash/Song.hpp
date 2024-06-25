
#ifndef _SONG
#define _SONG
#include "Containers.hpp"
#include "TimedTone.hpp"
#include "String.hpp"

namespace smash {
    class Song;

    class Song {
        Song();
        Song(std::string name, std::vector<TimedTone>& tones);
        std::vector<TimedTone> m_Tones;
 
        public: 
            std::vector<TimedTone> getCurrentTones(float currentTime);
            void addTone(const TimedTone& tone);
            void removeTone(float startTime);
    };
}

#endif
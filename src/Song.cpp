#include <smash.h>

namespace smash {

Song::Song() {}

Song::Song(std::string name, std::vector<TimedTone>& tones)
    : m_Tones(tones) {}

std::vector<TimedTone> Song::getCurrentTones(float currentTime) {
    std::vector<TimedTone> currentTones;
    
    // Binary search to find the first tone that starts after the current time
    int left = 0;
    int right = m_Tones.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (m_Tones[mid].startTime <= currentTime) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    // Iterate from the found position to the end of the vector
    for (int i = right + 1; i < m_Tones.size() && m_Tones[i].startTime <= currentTime; i++) {
        currentTones.push_back(m_Tones[i]);
    }
    
    return currentTones;
}

void Song::addTone(const TimedTone& tone) {
    // Binary search to find the correct position to insert the new tone
    int left = 0;
    int right = m_Tones.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (m_Tones[mid].startTime < tone.startTime) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    // Insert the new tone at the found position
    m_Tones.insert(m_Tones.begin() + left, tone);
}

void Song::removeTone(float startTime) {
    // Binary search to find the range of tones with the specified start time
    int left = 0;
    int right = m_Tones.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (m_Tones[mid].startTime < startTime) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    // Erase the tones within the found range
    int startIndex = right + 1;
    while (startIndex < m_Tones.size() && m_Tones[startIndex].startTime == startTime) {
        m_Tones.erase(m_Tones.begin() + startIndex);
    }
}
}

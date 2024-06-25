
#include <smash.h>

#ifdef _WIN32
#include <chrono>
#endif

namespace smash
{
    TimeSystem Time::s_TimeSystem;

    TimeSystem::TimeSystem()
    :   m_ApplicationBeginTime(Time::getNowTime()),
        m_FrameBeginTime(0.0),
        m_DeltaTime(0.0) {}

    double TimeSystem::getRunningTime() const {
        return Time::getNowTime() - m_ApplicationBeginTime;
    }

    double TimeSystem::getDeltaTime() const {
        return m_DeltaTime;
    }

    double Time::getRunningTime() {
        return s_TimeSystem.getRunningTime();
    }

    double Time::getDeltaTime() {
        return s_TimeSystem.getDeltaTime();
    }

double Time::getNowTime() {
#ifdef _WIN32
    auto now = std::chrono::high_resolution_clock::now();
    auto duration = now.time_since_epoch();
    return std::chrono::duration<double>(duration).count();
#endif
#ifdef ARDUINO
    return millis() / 1000.0;
#endif
}

    void Time::registerFrameBegin() {
        s_TimeSystem.m_FrameBeginTime = getNowTime();
    }

    void Time::updateDeltaTime() {
        s_TimeSystem.m_DeltaTime = getNowTime() - s_TimeSystem.m_FrameBeginTime;
    }
}

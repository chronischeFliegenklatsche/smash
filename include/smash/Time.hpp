#ifndef _TIME_HPP
#define _TIME_HPP

namespace smash
{
    class TimeSystem;
    class Time;
    
    class TimeSystem
    {
        friend class Time;
        double m_ApplicationBeginTime;
        double m_FrameBeginTime;
        double m_DeltaTime;
    public:
        TimeSystem();
        double getRunningTime() const;
        double getDeltaTime() const;
    };

    class Time
    {
        friend class Runtime;
        static TimeSystem s_TimeSystem;

        static void registerFrameBegin();
        static void updateDeltaTime();

    public:
        static double getRunningTime();
        static double getDeltaTime();
        static double getNowTime();
    };
}

#endif
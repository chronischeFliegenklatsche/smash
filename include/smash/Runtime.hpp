#ifndef _RUNTIME_HPP
#define _RUNTIME_HPP

namespace smash
{
    class Runtime;
    class Application;

    class Runtime
    {
        mutable bool m_RuntimeExitQueued;
    public:

        Runtime();
        virtual ~Runtime();

        virtual void pipe() const;

        void queueRuntimeExit() const;
        bool getRuntimeExitQueued() const;
    };

    class Application
    {
        friend class Runtime;
        static const Runtime *m_CurrentRuntime;
    public:
        static void queueApplicationExit();
        static bool getApplicationExitQueued();
    };
}
#endif

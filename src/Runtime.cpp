
#include <smash.h>

namespace smash
{
    const Runtime *Application::s_CurrentRuntime = nullptr;

    Runtime::Runtime() {
#ifdef ESP32
        smash::Diagnostics::initializeSerialConnection();
#endif
        Application::s_CurrentRuntime = this;
        Diagnostics::print("Runtime initialized.");
    }

    void Runtime::pipe() const
    {
        Time::registerFrameBegin();
        Application::s_CurrentRuntime = this;
        InputDetection::updateInputs();
        SceneManagement::updateActiveScene();
        Rendering::render();
        Time::updateDeltaTime();
    }

    void Runtime::queueRuntimeExit() const {
        //InputDetection::shutdown();
        //Rendering::shutdown();
        m_RuntimeExitQueued = true;
    }

    bool Runtime::getRuntimeExitQueued() const {
        return m_RuntimeExitQueued;
    }

    Runtime::~Runtime() {
        Diagnostics::print("Runtime destroyed.");
    }

    void Application::queueApplicationExit() {
        if (s_CurrentRuntime) {
            s_CurrentRuntime->queueRuntimeExit();
        }
    }

    bool Application::getApplicationExitQueued() {
        if (s_CurrentRuntime) {
            return s_CurrentRuntime->getRuntimeExitQueued();
        }
        return false;
    }   

}

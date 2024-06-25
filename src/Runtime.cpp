#ifdef _RUNTIME_HPP
#include <smash.h>

namespace smash
{
    const Runtime *Application::m_CurrentRuntime = nullptr;

    Runtime::Runtime() {
        Application::m_CurrentRuntime = this;
        Diagnostics::print("Runtime initialized.");
    }

    void Runtime::pipe() const
    {
        Time::registerFrameBegin();
        Application::m_CurrentRuntime = this;
        InputDetection::updateInputs();
        SceneManagement::updateActiveScene();
        Rendering::render();
        Time::updateDeltaTime();
    }

    void Runtime::queueRuntimeExit() const {
        m_RuntimeExitQueued = true;
    }

    bool Runtime::getRuntimeExitQueued() const {
        return m_RuntimeExitQueued;
    }

    Runtime::~Runtime() {
        Diagnostics::print("Runtime destroyed.");
    }

    void Application::queueApplicationExit() {
        if (m_CurrentRuntime) {
            m_CurrentRuntime->queueRuntimeExit();
        }
    }

    bool Application::getApplicationExitQueued() {
        if (m_CurrentRuntime) {
            return m_CurrentRuntime->getRuntimeExitQueued();
        }
        return false;
    }   

}
#endif

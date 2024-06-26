
#include <smash.h>

namespace smash
{
    InputDetector InputDetection::m_InputDetector;

    InputDetector::InputDetector() : m_InputAPI(nullptr)
    {
    }

    InputDetector::~InputDetector()
    {
        if (m_InputAPI)
        {
            m_InputAPI->~InputAPI();
        }
    }

    void InputDetector::bindInputAPI(std::unique_ptr<InputAPI> inputAPI)
    {
        m_InputAPI = std::move(inputAPI);
    }

    void InputDetector::updateInputs(InputSystem& inputSystem) const
    {
        if (m_InputAPI)
        {
            m_InputAPI->updateInputs(inputSystem);
            m_InputAPI->finishFrame();
        }
    }

    void InputDetection::bindInputAPI(std::unique_ptr<InputAPI> inputAPI)
    {
        m_InputDetector.bindInputAPI(std::move(inputAPI));
    }

    void InputDetection::updateInputs()
    {
        m_InputDetector.updateInputs(Input::m_InputSystem);
    }

    void InputDetection::shutdown()
    {
        m_InputDetector.~InputDetector();
    }
}

#include <smash.h>

namespace smash
{
    InputDetector InputDetection::m_InputDetector;

    InputDetector::InputDetector() : m_InputAPI(nullptr)
    {
    }

    InputDetector::InputDetector(std::shared_ptr<InputAPI> inputAPI)
        : m_InputAPI(inputAPI)
    {
    }

    InputDetector::~InputDetector()
    {
    }

    void InputDetector::setInputAPI(std::shared_ptr<const InputAPI> inputAPI)
    {
        m_InputAPI = inputAPI;
    }

    std::shared_ptr<const InputAPI> InputDetector::getInputAPI() const
    {
        return m_InputAPI;
    }

    void InputDetector::updateInputs(InputSystem& inputSystem) const
    {
        if (m_InputAPI)
        {
            m_InputAPI->updateInputs(inputSystem);
            m_InputAPI->finishFrame();
        }
    }

    void InputDetection::setInputAPI(std::shared_ptr<const InputAPI> inputAPI)
    {
        m_InputDetector.setInputAPI(inputAPI);
    }

    std::shared_ptr<const InputAPI> InputDetection::getInputAPI()
    {
        return m_InputDetector.getInputAPI();
    }

    void InputDetection::updateInputs()
    {
        m_InputDetector.updateInputs(Input::m_InputSystem);
    }
}
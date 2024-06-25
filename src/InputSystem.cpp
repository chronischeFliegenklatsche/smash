#ifdef _INPUT_SYSTEM_HPP
#include <smash.h>

namespace smash
{
    InputSystem::InputSystem()
    {
    }

    float InputSystem::getAxis(const std::string& axis) const
    {
        auto it = m_InputAxes.find(axis);
        if (it != m_InputAxes.end())
            return it->second;
        return 0.0f;
    }

    bool InputSystem::getButton(const std::string& button) const
    {
        auto it = m_InputButtons.find(button);
        if (it != m_InputButtons.end())
            return it->second;
        return false;
    }

    bool InputSystem::getButtonPressed(const std::string& button) const
    {
        auto it = m_InputButtons.find(button);
        auto prevIt = m_PrevInputButtons.find(button);
        if (it != m_InputButtons.end() && prevIt != m_PrevInputButtons.end())
            return it->second && !prevIt->second;
        return false;
    }

    bool InputSystem::getButtonReleased(const std::string& button) const
    {
        auto it = m_InputButtons.find(button);
        auto prevIt = m_PrevInputButtons.find(button);
        if (it != m_InputButtons.end() && prevIt != m_PrevInputButtons.end())
            return !it->second && prevIt->second;
        return false;
    }

    bool InputSystem::getKey(KeyCodes keyCode) const
    {
        auto it = m_InputKeys.find(keyCode);
        if (it != m_InputKeys.end())
            return it->second;
        return false;
    }

    void InputSystem::setAxis(const std::string& axis, float value)
    {
        m_InputAxes[axis] = value;
    }

    void InputSystem::increaseAxis(const std::string& axis, float value)
    {
        m_InputAxes[axis] += value;
    }

    void InputSystem::setButtonState(const std::string& button, bool hold)
    {
        m_InputButtons[button] = hold;
    }

    void InputSystem::setKeyState(KeyCodes keyCode, bool hold)
    {
        m_InputKeys[keyCode] = hold;
    }

    // Input class implementation
    InputSystem Input::m_InputSystem;

    float Input::getAxis(const std::string& axis)
    {
        return m_InputSystem.getAxis(axis);
    }

    bool Input::getButton(const std::string& button)
    {
        return m_InputSystem.getButton(button);
    }

    bool Input::getButtonPressed(const std::string& button)
    {
        return m_InputSystem.getButtonPressed(button);
    }

    bool Input::getButtonReleased(const std::string& button)
    {
        return m_InputSystem.getButtonReleased(button);
    }

    bool Input::getKey(KeyCodes keyCode)
    {
        return m_InputSystem.getKey(keyCode);
    }

    void Input::setAxis(const std::string& axis, float value)
    {
        m_InputSystem.setAxis(axis, value);
    }

    void Input::increaseAxis(const std::string& axis, float value)
    {
        m_InputSystem.increaseAxis(axis, value);
    }

    void Input::setButtonState(const std::string& button, bool hold)
    {
        m_InputSystem.setButtonState(button, hold);
    }

    void Input::setKeyState(KeyCodes keyCode, bool hold)
    {
        m_InputSystem.setKeyState(keyCode, hold);
    }
}
#endif
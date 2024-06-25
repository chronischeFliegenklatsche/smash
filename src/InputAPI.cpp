#include <smash.h>

namespace smash
{
    InputAPI::InputAPI()
    {
        // Constructor implementation (if needed)
    }

    InputAPI::~InputAPI()
    {
        // Destructor implementation (if needed)
    }

    void InputAPI::setAxis(InputSystem& inputSystem, const std::string& axis, float value) const
    {
        inputSystem.setAxis(axis, value);
    }

    void InputAPI::setButtonState(InputSystem& inputSystem, const std::string& button, bool hold) const
    {
        inputSystem.setButtonState(button, hold);
    }

    void InputAPI::setKeyState(InputSystem& inputSystem, KeyCodes keyCode, bool hold) const
    {
        inputSystem.setKeyState(keyCode, hold);
    }

}
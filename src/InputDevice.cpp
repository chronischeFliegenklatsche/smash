#ifdef _INPUT_DEVICE_HPP
#include <smash.h>

namespace smash
{
    InputDevice::InputDevice() {    
    }
    InputDevice::~InputDevice() {
    }

    void InputDevice::setButtonState(InputSystem& inputSystem, const std::string& button, bool hold) const {
        inputSystem.setButtonState(button, hold);
    }
}
#endif
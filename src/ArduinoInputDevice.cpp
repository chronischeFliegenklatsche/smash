#ifdef ARDUINO
#include <smash.h>

namespace smash
{
    ArduinoInputDevice::ArduinoInputDevice() {    
    }
    ArduinoInputDevice::~ArduinoInputDevice() {
    }

    void ArduinoInputDevice::setButtonState(InputSystem& inputSystem, const std::string& button, bool hold) const {
        inputSystem.setButtonState(button, hold);
    }
}
#endif
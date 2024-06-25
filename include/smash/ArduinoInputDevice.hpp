#ifndef _ARDUINO_INPUT_DEVICE_HPP
#define _ARDUINO_INPUT_DEVICE_HPP

#include "InputSystem.hpp"

namespace smash
{
    class ArduinoInputDevice;

    class ArduinoInputDevice
    {
    protected:
        void setButtonState(InputSystem& inputSystem, const std::string& button, bool hold) const;  
    public:
        ArduinoInputDevice();
        virtual ~ArduinoInputDevice();
        
        virtual void provideInputs(InputSystem& inputSystem) const = 0;
    };
}
#endif
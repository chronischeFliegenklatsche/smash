#ifndef _ARDUINO_INPUT_DEVICE_HPP
#define _ARDUINO_INPUT_DEVICE_HPP

#include "InputSystem.hpp"

namespace smash
{
    class InputDevice;

    class InputDevice
    {
    protected:
        void setButtonState(InputSystem& inputSystem, const std::string& button, bool hold) const;  
    public:
        InputDevice();
        virtual ~InputDevice();
        
        virtual void provideInputs(InputSystem& inputSystem) const = 0;
    };
}
#endif
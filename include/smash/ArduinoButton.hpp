#ifndef _ARDUINO_BUTTON_HPP
#define _ARDUINO_BUTTON_HPP

#include "ArduinoInputDevice.hpp"
#include "String.hpp"

namespace smash
{
    class ArduinoButton;
    
    class ArduinoButton : public InputDevice
    {
        std::string m_ButtonName;
        int m_Pin;

        bool getState() const;
    public:

        ArduinoButton();
        ArduinoButton(int pin, const std::string& buttonName);
        
        void provideInputs(InputSystem& inputSystem) const override;
    };
}

#endif
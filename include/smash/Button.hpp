#ifndef _BUTTON_HPP
#define _BUTTON_HPP

#include "InputDevice.hpp"
#include "String.hpp"

namespace smash
{
    class Button;
    
    class Button : public InputDevice
    {
        std::string m_ButtonName;
        int m_Pin;

        bool getState() const;
    public:

        Button();
        Button(int pin, const std::string& buttonName);
        
        void provideInputs(InputSystem& inputSystem) const override;
    };
}

#endif
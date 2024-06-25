#ifndef _INPUT_API_HPP
#define _INPUT_API_HPP

#include "SmartPointers.hpp"
#include "InputSystem.hpp"

namespace smash
{
    class InputAPI;
    class InputAPI
    {
    protected:
        void setAxis(InputSystem& inputSystem, const std::string& axis, float value) const;
        void setButtonState(InputSystem& inputSystem, const std::string& button, bool hold) const;
        void setKeyState(InputSystem& inputSystem, KeyCodes keyCode, bool hold) const;
    public:
    
        InputAPI();
        virtual ~InputAPI();
        
        virtual void updateInputs(InputSystem& inputSystem) const = 0;
        virtual void finishFrame() const = 0;
    };
}

#endif
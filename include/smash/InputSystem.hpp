#ifndef _INPUT_SYSTEM_HPP
#define _INPUT_SYSTEM_HPP

#include "Containers.hpp"
#include "String.hpp"
#include "KeyCodes.hpp"

namespace smash
{
    class InputSystem;
    class Input;
    class InputDetection;

    class InputSystem
    {
        std::map<const std::string, float> m_InputAxes;

        std::map<const std::string, bool> m_InputButtons;
        std::map<const std::string, bool> m_PrevInputButtons;

        std::map<const KeyCodes, bool> m_InputKeys;

        friend class Input;
        friend class InputAPI;
        friend class ArduinoInputDevice;
        void setAxis(const std::string& axis, float value);
        void increaseAxis(const std::string& axis, float value);

        void setButtonState(const std::string& button, bool hold);

        void setKeyState(KeyCodes keyCode, bool hold);
    public:

        InputSystem();

        float getAxis(const std::string& axis) const;

        bool getButton(const std::string& button) const;
        bool getButtonPressed(const std::string& button) const;
        bool getButtonReleased(const std::string& button) const;

        bool getKey(KeyCodes keyCode) const;    
    };

    class Input
    {
        friend class InputDetection;
        static InputSystem m_InputSystem;

        static void setAxis(const std::string& axis, float value);
        static void increaseAxis(const std::string& axis, float value);

        static void setButtonState(const std::string& button, bool hold);

        static void setKeyState(KeyCodes keyCode, bool hold);

    public:

        static float getAxis(const std::string& axis);

        static bool getButton(const std::string& button);
        static bool getButtonPressed(const std::string& button);
        static bool getButtonReleased(const std::string& button);

        static bool getKey(KeyCodes keyCode);    
    };
}

#endif
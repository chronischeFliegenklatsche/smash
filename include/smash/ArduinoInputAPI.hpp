#ifndef _ARDUINO_INPUT_API_HPP
#define _ARDUINO_INPUT_API_HPP

#include "Containers.hpp"
#include "InputAPI.hpp"
#include "InputDevice.hpp"
#include "SmartPointers.hpp"

namespace smash {
    class ArduinoInputAPI;
    class ArduinoInputAPI : public InputAPI
    {
        std::vector<std::shared_ptr<InputDevice>> m_InputDevices;   
    public:
    
        ArduinoInputAPI();
        ~ArduinoInputAPI() override;

        void addInputDevice(std::shared_ptr<InputDevice> inputDevice);
        bool removeInputDevice(std::shared_ptr<InputDevice> inputDevice);

        void updateInputs(InputSystem& inputSystem) const override;
        void finishFrame() const override;
    };
}

#endif
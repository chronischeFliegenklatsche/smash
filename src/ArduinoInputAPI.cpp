#ifdef _ARDUINO_INPUT_API_HPP
#include <smash.h>

#ifdef _ARDUINO_INPUT_API_HPP
namespace smash {

    ArduinoInputAPI::ArduinoInputAPI() {
    };

    ArduinoInputAPI::~ArduinoInputAPI() {
    };

    void ArduinoInputAPI::addInputDevice(std::shared_ptr<InputDevice> inputDevice) {
        m_InputDevices.push_back(inputDevice);
    };

    bool ArduinoInputAPI::removeInputDevice(std::shared_ptr<InputDevice> inputDevice) {
        for (auto it = m_InputDevices.begin(); it != m_InputDevices.end(); ++it) {
            if (*it == inputDevice) {
                m_InputDevices.erase(it);
                return true;
            }
        }
        return false;
    };

    void ArduinoInputAPI::updateInputs(InputSystem& inputSystem) const {
        for (auto inputDevice : m_InputDevices) {
            inputDevice->provideInputs(inputSystem);
        }
    };

    void ArduinoInputAPI::finishFrame() const {
    };
    
}
#endif
#endif
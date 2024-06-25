#ifdef ARDUINO
#include <smash.h>

namespace smash {

    ArduinoInputAPI::ArduinoInputAPI() {
    };

    ArduinoInputAPI::~ArduinoInputAPI() {
    };

    void ArduinoInputAPI::addInputDevice(std::shared_ptr<ArduinoInputDevice> inputDevice) {
        m_InputDevices.push_back(inputDevice);
    };

    bool ArduinoInputAPI::removeInputDevice(std::shared_ptr<ArduinoInputDevice> inputDevice) {
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
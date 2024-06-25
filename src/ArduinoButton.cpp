#ifdef ARDUINO
#include <smash.h>

namespace smash {

    ArduinoButton::ArduinoButton() : m_Pin(0), m_ButtonName("ArduinoButton") {
        pinMode(m_Pin, INPUT);
    };

    ArduinoButton::ArduinoButton(int pin, const std::string& buttonName) : m_Pin(pin), m_ButtonName(buttonName) {
    };    

    bool ArduinoButton::getState() const {
        return digitalRead(m_Pin) == HIGH;
    };

    void ArduinoButton::provideInputs(InputSystem& inputSystem) const {
        setButtonState(inputSystem, m_ButtonName, getState());
    };  

}
#endif
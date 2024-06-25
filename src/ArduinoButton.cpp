#ifdef _ARDUINO_BUTTON_HPP
#include <smash.h>

#ifdef ARDUINO
#include <Arduino.h>
#endif

namespace smash {

    ArduinoButton::ArduinoButton() : m_Pin(0), m_ButtonName("ArduinoButton") {
        pinMode(m_Pin, INPUT);
    };

    ArduinoButton::ArduinoButton(int pin, const std::string& buttonName) : m_Pin(pin), m_ButtonName(buttonName) {
    };    

    bool ArduinoButton::getState() const {
#ifdef ARDUINO
        return digitalRead(m_Pin) == HIGH;
#endif
        return false;
    };

    void ArduinoButton::provideInputs(InputSystem& inputSystem) const {
        setButtonState(inputSystem, m_ButtonName, getState());
    };  

}
#endif
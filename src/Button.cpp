#ifdef ARDUINO
#include <smash.h>

#ifdef ARDUINO
#include <Arduino.h>
#endif

namespace smash {

    Button::Button() : m_Pin(0), m_ButtonName("Button") {
        pinMode(m_Pin, INPUT);
    };

    Button::Button(int pin, const std::string& buttonName) : m_Pin(pin), m_ButtonName(buttonName) {
    };    

    bool Button::getState() const {
#ifdef ARDUINO
        return digitalRead(m_Pin) == HIGH;
#endif
        return false;
    };

    void Button::provideInputs(InputSystem& inputSystem) const {
        setButtonState(inputSystem, m_ButtonName, getState());
    };  

}
#endif
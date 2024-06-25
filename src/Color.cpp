#include <smash.h>

namespace smash
{
    // Constructors
    Color::Color() : r(0), g(0), b(0), a(255) {}

    Color::Color(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
        : r(red), g(green), b(blue), a(alpha) {}

    // Getters
    uint8_t Color::getRed() const { return r; }
    uint8_t Color::getGreen() const { return g; }
    uint8_t Color::getBlue() const { return b; }
    uint8_t Color::getAlpha() const { return a; }

    // Setters
    void Color::setRed(uint8_t red) { r = red; }
    void Color::setGreen(uint8_t green) { g = green; }
    void Color::setBlue(uint8_t blue) { b = blue; }
    void Color::setAlpha(uint8_t alpha) { a = alpha; }

    // RGB format (uint16_t)
    uint16_t Color::getRGB16() const {
        uint16_t red = static_cast<uint16_t>(r) >> 3;
        uint16_t green = static_cast<uint16_t>(g) >> 2;
        uint16_t blue = static_cast<uint16_t>(b) >> 3;
        return (red << 11) | (green << 5) | blue;
    }
}
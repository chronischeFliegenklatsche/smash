#include <smash.h>

namespace smash
{
    Color::Color() : r(0), g(0), b(0) {}

    Color::Color(uint8_t red, uint8_t green, uint8_t blue) : r(red), g(green), b(blue) {}

    uint16_t Color::getRGB16() const
    {
        return (r << 11) | (g << 5) | b;
    }

    const Color Color::black(0, 0, 0);
    const Color Color::white(255, 255, 255);
    const Color Color::red(255, 0, 0);
    const Color Color::green(0, 255, 0);
    const Color Color::blue(0, 0, 255);
}
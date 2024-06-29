#ifndef _COLOR_HPP
#define _COLOR_HPP

#include <stdint.h>

namespace smash
{
    class Color {
    public:
        // Constructors
        Color();
        Color(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha = 255);

        // Getters
        uint8_t getRed() const;
        uint8_t getGreen() const;
        uint8_t getBlue() const;
        uint8_t getAlpha() const;

        // Setters
        void setRed(uint8_t red);
        void setGreen(uint8_t green);
        void setBlue(uint8_t blue);
        void setAlpha(uint8_t alpha);

        // RGB format (uint16_t)
        uint16_t getRGB16() const;

    private:
        uint8_t r, g, b, a;
    };
}
#endif
#ifndef _COLOR_HPP
#define _COLOR_HPP

#include <stdint.h>

namespace smash
{
    struct Color;
    struct Color
    {
        uint8_t r, g, b;

        // Constructors
        Color();
        Color(uint8_t red, uint8_t green, uint8_t blue);

        // RGB format (uint16_t)
        uint16_t getRGB16() const;

        // Compare
        bool operator==(const Color& other) const
        {
            return r == other.r && g == other.g && b == other.b;
        }

        bool operator!=(const Color& other) const
        {
            return !(*this == other);
        }

        // Static colors
        static const Color black;
        static const Color white;
        static const Color red;
        static const Color green;
        static const Color blue;
    };
}
#endif
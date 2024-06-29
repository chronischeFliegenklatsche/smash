#ifndef _COLOR_HPP
#define _COLOR_HPP

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

        // Static colors
        static const Color black;
        static const Color white;
        static const Color red;
        static const Color green;
        static const Color blue;
    };
}
#endif
#ifndef _CANVAS_HPP
#define _CANVAS_HPP

#include "Color.hpp"

namespace smash
{
    class Canvas
    {
    private:
        Color *m_Pixels;
        size_t width;
        size_t height;

    public:
        Canvas(size_t w, size_t h);
        ~Canvas();

        size_t getWidth() const;
        size_t getHeight() const;

        void setPixel(size_t x, size_t y, Color color);
        Color getPixel(size_t x, size_t y) const;
        void clear(Color color);
    };
}
#endif
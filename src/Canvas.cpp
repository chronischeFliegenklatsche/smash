
#include <smash.h>
#include <algorithm>

namespace smash
{
    Canvas::Canvas(size_t w, size_t h) : width(w), height(h)
    {
        m_Pixels = new Color[width * height];
    }

    Canvas::~Canvas()
    {
        delete[] m_Pixels;
    }

    void Canvas::setPixel(size_t x, size_t y, Color color)
    {
        if (x < width && y < height)
        {
            m_Pixels[y * width + x] = color;
        }
    }

    Color Canvas::getPixel(size_t x, size_t y) const
    {
        if (x < width && y < height)
        {
            return m_Pixels[y * width + x];
        }
        return Color(); // Return default color if out of bounds
    }

    void Canvas::clear(Color color)
    {
        std::fill(m_Pixels, m_Pixels + (width * height), color);
    }

    size_t Canvas::getWidth() const
    {
        return width;
    }

    size_t Canvas::getHeight() const
    {
        return height;
    }
}
#include <smash.h>

namespace smash
{
    Experimental_GlRgbMatrixAPI::Experimental_GlRgbMatrixAPI(size_t _pixelScalar) : m_PixelScalar(_pixelScalar), m_GlRenderer()
    {
    }

    Experimental_GlRgbMatrixAPI::~Experimental_GlRgbMatrixAPI()
    {
    }

    void Experimental_GlRgbMatrixAPI::drawPixel(int x, int y, uint16_t color) const
    {
        x *= m_PixelScalar;
        y *= m_PixelScalar;
        m_GlRenderer.drawRect(x, y, m_PixelScalar, m_PixelScalar, color);
    }

    void Experimental_GlRgbMatrixAPI::drawRect(int x, int y, int w, int h, uint16_t color) const
    {
        x *= m_PixelScalar;
        y *= m_PixelScalar;
        w *= m_PixelScalar;
        h *= m_PixelScalar;
        m_GlRenderer.drawRect(x, y, w, h, color);
    }

    void Experimental_GlRgbMatrixAPI::drawCanvas(const Canvas& _canvas) const
    {
        for (size_t y = 0; y < _canvas.getHeight(); y++)
        {
            for (size_t x = 0; x < _canvas.getWidth(); x++)
            {
                drawPixel(x, y, _canvas.getPixel(x, y).getRGB16());
            }
        }
    }
}
#include <smash.h>

namespace smash
{

ScaledGLRenderingAPI::ScaledGLRenderingAPI(size_t pixelScalar)
    : GLRenderingAPI(), m_PixelScalar(pixelScalar)
{
    Diagnostics::print("ScaledGLRenderingAPI constructor called with scalar: " + std::to_string(m_PixelScalar));
}

void ScaledGLRenderingAPI::drawPixel(int x, int y, uint16_t color) const
{
    for (size_t dy = 0; dy < m_PixelScalar; ++dy)
    {
        for (size_t dx = 0; dx < m_PixelScalar; ++dx)
        {
            GLRenderingAPI::drawPixel(x * m_PixelScalar + dx, y * m_PixelScalar + dy, color);
        }
    }
}

void ScaledGLRenderingAPI::drawRect(int x, int y, int w, int h, uint16_t color) const
{
    for (int j = 0; j < h; ++j)
    {
        for (int i = 0; i < w; ++i)
        {
            drawPixel(x + i, y + j, color);
        }
    }
}

void ScaledGLRenderingAPI::drawCanvas(const Canvas& _canvas) const
{
    for (size_t y = 0; y < _canvas.getHeight(); ++y)
    {
        for (size_t x = 0; x < _canvas.getWidth(); ++x)
        {
            drawPixel(x, y, _canvas.getPixel(x, y).getRGB16());
        }
    }
}

size_t ScaledGLRenderingAPI::getCanvasWidth() const
{
    return GLRenderingAPI::getCanvasWidth() / m_PixelScalar;
}

size_t ScaledGLRenderingAPI::getCanvasHeight() const
{
    return GLRenderingAPI::getCanvasHeight() / m_PixelScalar;
}

}
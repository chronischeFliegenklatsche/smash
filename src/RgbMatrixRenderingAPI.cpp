#ifdef ESP32
#include <smash.h>

namespace smash
{
    RgbMatrixRenderingAPI::RgbMatrixRenderingAPI(HUB75_I2S_CFG mxconfig) : m_Matrix(ensureDoubleBuff(mxconfig))
    {
        m_Matrix.begin();
    }

    RgbMatrixRenderingAPI::~RgbMatrixRenderingAPI()
    {
    }

    void RgbMatrixRenderingAPI::drawPixel(int x, int y, uint16_t color) const
    {
        m_Matrix.drawPixel(x, y, color);
    }

    void RgbMatrixRenderingAPI::swapFrameBuffers() const
    {
        m_Matrix.flipDMABuffer();
        m_Matrix.clearScreen();
    }

    HUB75_I2S_CFG RgbMatrixRenderingAPI::ensureDoubleBuff(HUB75_I2S_CFG config)
    {
        config.double_buff = true;
        return config;
    }

    void RgbMatrixRenderingAPI::drawRect(int x, int y, int w, int h, uint16_t color) const
    {
        m_Matrix.fillRect(x, y, w, h, color);
    }

    size_t RgbMatrixRenderingAPI::getCanvasWidth() const
    {
        return m_Matrix.width();
    }

    size_t RgbMatrixRenderingAPI::getCanvasHeight() const
    {
        return m_Matrix.height();
    }

    void RgbMatrixRenderingAPI::drawCanvas(const Canvas& _canvas) const
    {
        for (int x = 0; x < _canvas.getWidth(); x++)
        {
            for (int y = 0; y < _canvas.getHeight(); y++)
            {
                drawPixel(x, y, _canvas.getPixel((size_t)x, (size_t)y).getRGB16());
            }
        }
    }

}
#endif

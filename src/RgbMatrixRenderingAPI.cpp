#ifdef ARDUINO
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
        Diagnostics::print("Pixel X " + std::to_string(x));
        Diagnostics::print("Pixel Y " + std::to_string(y));
        
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

}

#endif
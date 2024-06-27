#ifdef ARDUINO
#include <smash.h>

namespace smash
{
    RgbMatrixRenderingAPI::RgbMatrixRenderingAPI(HUB75_I2S_CFG mxconfig) : m_Matrix(mxconfig)
    {
        mxconfig.double_buff = true;
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
}

#endif
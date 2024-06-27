#ifdef ARDUINO
#ifndef _RGB_MATRIX_RENDERING_API_HPP
#define _RGB_MATRIX_RENDERING_API_HPP

#include "RenderingAPI.hpp"
#include <ESP32-HUB75-MatrixPanel-I2S-DMA.h>

namespace smash
{
    class RgbMatrixRenderingAPI : public RenderingAPI
    {
        mutable MatrixPanel_I2S_DMA m_Matrix;
        HUB75_I2S_CFG ensureDoubleBuff(HUB75_I2S_CFG config);
    public:
        RgbMatrixRenderingAPI(HUB75_I2S_CFG mxconfig);
        ~RgbMatrixRenderingAPI() override;
        void drawPixel(int x, int y, uint16_t color) const override;
        void swapFrameBuffers() const override;
    };
}
#endif
#endif
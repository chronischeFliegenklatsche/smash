#ifdef _RGB_MATRIX_RENDERING_API_HPP
#include <smash.h>

namespace smash
{

    RgbMatrixRenderingAPI::RgbMatrixRenderingAPI(RgbMatrixPinConfiguration cfg)
    : m_Matrix(cfg.width, cfg.bitDepth, 6, cfg.rgbPins, 4, cfg.addrPins, cfg.clk, cfg.lat, cfg.oe, true)
    {
        if (!m_Matrix.begin()) {
            Diagnostics::print("Matrix initialization failed!");
            return;
        }
    }

    RgbMatrixRenderingAPI::~RgbMatrixRenderingAPI() {
    }


    void RgbMatrixRenderingAPI::drawPixel(int x, int y, uint16_t color) const {
        m_Matrix.drawPixel(x, y, color);
    }
    
    void RgbMatrixRenderingAPI::swapFrameBuffers() const {
        m_Matrix.show();
    }
}
#endif
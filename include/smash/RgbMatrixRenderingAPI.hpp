#ifndef _RGB_MATRIX_RENDERING_API_HPP
#define _RGB_MATRIX_RENDERING_API_HPP

#include "RenderingAPI.hpp"
#include <Adafruit_Protomatter.h>

namespace smash
{

    struct RgbMatrixPinConfiguration;
    class RgbMatrixRenderingAPI;

    struct RgbMatrixPinConfiguration
    {
        uint8_t width;
        uint8_t bitDepth;
        uint8_t *rgbPins;
        uint8_t *addrPins;
        uint8_t clk;
        uint8_t lat;
        uint8_t oe;
    };

    class RgbMatrixRenderingAPI : public RenderingAPI
    {
        mutable Adafruit_Protomatter m_Matrix;
    public:

        RgbMatrixRenderingAPI(RgbMatrixPinConfiguration cfg);
        virtual ~RgbMatrixRenderingAPI();

        void drawPixel(int x, int y, uint16_t color) const override;
        void swapFrameBuffers() const override;
    };
}

#endif
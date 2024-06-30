#ifndef _EXP_GL_RGB_MATRIX_API_HPP
#define _EXP_GL_RGB_MATRIX_API_HPP

#include "GLRenderingAPI.hpp"

namespace smash
{
    class Experimental_GlRgbMatrixAPI : public RenderingAPI
    {
        size_t m_PixelScalar;
        GLRenderingAPI m_GlRenderer;
    public:

        Experimental_GlRgbMatrixAPI(size_t _pixelScalar);
        virtual ~Experimental_GlRgbMatrixAPI() override;

        void drawPixel(int x, int y, uint16_t color) const override;
        void drawRect(int x, int y, int w, int h, uint16_t color) const override;
        void drawCanvas(const Canvas& _canvas) const override;
    };
}

#endif
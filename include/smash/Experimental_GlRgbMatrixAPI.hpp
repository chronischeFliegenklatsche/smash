#ifndef _EXP_GL_RGB_MATRIX_API_HPP
#define _EXP_GL_RGB_MATRIX_API_HPP

#include "GLRenderingAPI.hpp"

namespace smash
{
    class ScaledGLRenderingAPI : public GLRenderingAPI
        {
        private:
            size_t m_PixelScalar;

        public:
            ScaledGLRenderingAPI(size_t pixelScalar);
            ~ScaledGLRenderingAPI() override = default;

            void drawPixel(int x, int y, uint16_t color) const override;
            void drawRect(int x, int y, int w, int h, uint16_t color) const override;
            void drawCanvas(const Canvas& _canvas) const override;

            size_t getCanvasWidth() const override;
            size_t getCanvasHeight() const override;
        };
}

#endif
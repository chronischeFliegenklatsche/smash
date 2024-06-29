#ifndef _RECT_SHADER_HPP
#define _RECT_SHADER_HPP

#include "FragmentShader.hpp"

namespace smash
{
    class RectShader : public FragmentShader
    {
        const float *x;
        const float *y;
        const float *w;
        const float *h;
        const Color *color;
    public:

        RectShader();
        RectShader(const float* x, const float* y, const float* w, const float* h, const Color* color);
        ~RectShader() override {}

        void fragment(size_t x, size_t y, Color& color) const override;
    };
}   

#endif
#ifndef _RECT_SHADER_HPP
#define _RECT_SHADER_HPP

#include "FragmentShader.hpp"

namespace smash
{
    class RectShader : public FragmentShader
    {
    public:

        RectShader() = default;
        ~RectShader() override = default;

        void fragment(size_t x, size_t y, Color& color) const override;
    };
}   

#endif
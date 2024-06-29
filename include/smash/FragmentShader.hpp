#ifndef _FRAGMENT_SHADER_HPP
#define _FRAGMENT_SHADER_HPP

#include "Shader.hpp"
#include <cstddef> 

namespace smash
{
    class FragmentShader : public Shader
    {
    public:

        FragmentShader() = default;
        virtual ~FragmentShader() = default;

        virtual void shade(Canvas& _canvas) const override;
        virtual void fragment(size_t x, size_t y, Color& color) const = 0;
    };  
}

#endif
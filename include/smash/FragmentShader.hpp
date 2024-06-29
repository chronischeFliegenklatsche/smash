#ifndef _SHADER_HPP
#define _SHADER_HPP

#include "Canvas.hpp"
#include <cstddef> 

namespace smash
{
    class FragmentShader;
    class FragmentShader
    {
    public:

        FragmentShader() = default;
        virtual ~FragmentShader() = default;

        virtual void execute(Canvas& _canvas) const;
        virtual void fragment(size_t x, size_t y, Color& color) const = 0;
    };  
}

#endif
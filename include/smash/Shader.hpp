#ifndef _SHADER_HPP
#define _SHADER_HPP

#include "ShaderAttributes.hpp"
#include "Canvas.hpp"

namespace smash
{
    class Shader
    {
    public:
    
        Shader() = default;
        ~Shader() = default;

        void execute(ShaderAttributes& _shattr, Canvas& _canvas) const;
    protected:
        virtual void shade(Canvas& _canvas) const = 0;
    };
}

#endif
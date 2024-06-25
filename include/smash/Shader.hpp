#ifndef _SHADER_HPP
#define _SHADER_HPP

#include "ShaderUniforms.hpp"
#include "RenderingAPI.hpp"

namespace smash
{
    class Shader;

    class Shader
    {
    public:
        Shader();
        virtual ~Shader();
        virtual void shade(ShaderAttributes& _shAttr, const RenderingAPI* _renderAPI) const = 0;
    };
}

#endif
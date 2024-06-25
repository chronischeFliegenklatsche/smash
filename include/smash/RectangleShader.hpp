#ifndef _RECTANGLE_SHADER_HPP
#define _RECTANGLE_SHADER_HPP

#include "Shader.hpp"

namespace smash
{
    class RectangleShader;

    class RectangleShader : public Shader
    {
    public:
        RectangleShader();
        ~RectangleShader();

        void shade(ShaderAttributes& _shAttr, const RenderingAPI* _renderAPI) const override;
        
    };
}

#endif
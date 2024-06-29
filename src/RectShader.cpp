#include <smash.h>
#include <smash/sh.hpp>

namespace smash
{

    void RectShader::fragment(size_t x, size_t y, Color& color) const
    {
        vec2 pos = *(vec2*)(gp("m_Position"));
        vec2 scal = *(vec2*)(gp("m_Scale"));
        
        
        if ((float)x >= pos.x && (float)x < pos.x + scal.x && (float)y >= pos.y && (float)y < pos.y + scal.y)
        {
            color = *(Color*)(gp("m_Color"));
        }
        

    }
}
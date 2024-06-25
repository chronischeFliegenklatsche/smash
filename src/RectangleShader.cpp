#include <smash.h>

namespace smash {

    RectangleShader::RectangleShader()
    {}

    RectangleShader::~RectangleShader()
    {}

    typedef Vector2 vec2;
    typedef Color col;
    void RectangleShader::shade(ShaderAttributes& _shAttr, const RenderingAPI* _renderAPI) const {
        vec2 position = _shAttr.getVector("m_Position");
        vec2 size = _shAttr.getVector("m_Size");
        col color = _shAttr.getColor("m_Color");
        
        for (int x = position.x - size.x / 2; x < position.x + size.x / 2; ++x) {
            for (int y = position.y - size.y / 2; y < position.y + size.y / 2; ++y) {
                _renderAPI->drawPixel(x, y, color.getRGB16());
            }
        }
    }

}
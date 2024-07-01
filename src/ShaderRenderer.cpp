#include <smash.h>
#include <memory>

namespace smash
{

    std::unique_ptr<Component> ShaderRenderer::clone() const
    {
        return std::make_unique<ShaderRenderer>();
    }

    void ShaderRenderer::render(const RenderingAPI& _renderingAPI) const
    {
        
        m_ShaderProgram.use(*m_ShaderAttributes, _renderingAPI);

    }

    std::string ShaderRenderer::getTypeName() const
    {
        return "ShaderRenderer";
    }

    void ShaderRenderer::bindShaderAttributes(std::unique_ptr<ShaderAttributes> _shaderAttributes)
    {
        m_ShaderAttributes = std::move(_shaderAttributes);
    }

}
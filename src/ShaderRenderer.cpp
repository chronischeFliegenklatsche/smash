#include <smash.h>

namespace smash
{

    Component* ShaderRenderer::clone() const
    {
        return new ShaderRenderer();
    }

    void ShaderRenderer::update()
    {
        // Do nothing
    }

    void ShaderRenderer::render(const RenderingAPI& _renderingAPI) const
    {
        
        m_ShaderProgram.use(*m_StartFrameShaderAttributes, _renderingAPI);

    }

    std::string ShaderRenderer::getTypeName() const
    {
        return "ShaderRenderer";
    }

    void ShaderRenderer::bindStartFrameShaderAttributes(std::unique_ptr<ShaderAttributes> _shaderAttributes)
    {
        m_StartFrameShaderAttributes = std::move(_shaderAttributes);
    }

}
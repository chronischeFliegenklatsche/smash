#ifdef _RENDERER_HPP
#include <smash.h>

namespace smash
{
    Renderer Rendering::m_Renderer;

    Renderer::Renderer() : m_RenderingAPI(nullptr) {}

    void Renderer::setRenderingAPI(std::shared_ptr<const RenderingAPI> renderingAPI)
    {
        m_RenderingAPI = renderingAPI;
    }

    const std::shared_ptr<const RenderingAPI> Renderer::getRenderingAPI() const
    {
        return m_RenderingAPI;
    }

    void Renderer::render(const Scene* _scene) const
    {
        if (m_RenderingAPI && _scene)
        {
            for (const Component& component : _scene->_components)
            {
                const ShaderProgramProvider* shaderProgramProvider = nullptr;
#ifdef _WIN32
                shaderProgramProvider = dynamic_cast<const ShaderProgramProvider*>(&component);  
#endif
#ifdef ARDUINO
                if (ShaderProgramProvider::hasShaderProgram((TypeNameProvider*)&component))
                {
                    shaderProgramProvider = (const ShaderProgramProvider*)&component;
                }
#endif
                
                if (shaderProgramProvider)
                {
                    const ShaderProgram* shaderProgram = shaderProgramProvider->getShaderProgram().get();
                    if (shaderProgram)
                    {
                        shaderProgram->execute(m_RenderingAPI.get());
                    }   
                }
                
            }
            m_RenderingAPI->swapFrameBuffers();
        }
    }

    void Rendering::setRenderingAPI(std::shared_ptr<const RenderingAPI> renderingAPI)
    {
        m_Renderer.setRenderingAPI(renderingAPI);
    }

    const std::shared_ptr<const RenderingAPI> Rendering::getRenderingAPI()
    {
        return m_Renderer.getRenderingAPI();
    }

    void Rendering::render()
    {
        m_Renderer.render(SceneManagement::getActiveScene());
    }
}
#endif
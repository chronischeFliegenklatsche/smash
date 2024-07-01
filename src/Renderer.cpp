
#include <smash.h>

namespace smash
{
    Renderer Rendering::m_Renderer;

    Renderer::Renderer() : m_RenderingAPI(nullptr) {}

    void Renderer::bindRenderingAPI(std::unique_ptr<const RenderingAPI> renderingAPI)
    {
        m_RenderingAPI = std::move(renderingAPI);
    }

    void Renderer::render(const Scene* _scene) const
    {
        
        if (m_RenderingAPI && _scene)
        {
            for (const Component& component : _scene->m_Components)
            {
                component.render(*m_RenderingAPI);
                
            }
            m_RenderingAPI->swapFrameBuffers();  
        }
    }

    void Rendering::bindRenderingAPI(std::unique_ptr<const RenderingAPI> renderingAPI)
    {
        m_Renderer.bindRenderingAPI(std::move(renderingAPI));
    }


    void Rendering::render()
    {
        m_Renderer.render(SceneManagement::getActiveScene());
    }
}

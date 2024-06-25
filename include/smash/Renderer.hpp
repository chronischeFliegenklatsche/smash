#ifndef _RENDERER_HPP
#define _RENDERER_HPP

#include "SmartPointers.hpp"
#include "RenderingAPI.hpp"
#include "Scene.hpp"

namespace smash
{
    class Renderer;
    class Rendering;

    class Renderer
    {
        std::shared_ptr<const RenderingAPI> m_RenderingAPI;
    public:

        Renderer();

        void setRenderingAPI(std::shared_ptr<const RenderingAPI> renderingAPI);
        const std::shared_ptr<const RenderingAPI> getRenderingAPI() const;

        void render(const Scene* _scene) const;
    };

    class Rendering
    {
        static Renderer m_Renderer;
    public:

        static void setRenderingAPI(std::shared_ptr<const RenderingAPI> renderingAPI);

        static const std::shared_ptr<const RenderingAPI> getRenderingAPI();

        static void render();
    };
}

#endif
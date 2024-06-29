#ifndef _RENDERER_HPP
#define _RENDERER_HPP

#include <memory>

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
        std::shared_ptr<const RenderingAPI> getRenderingAPI() const;

        void render(const Scene* _scene) const;
    };

    class Rendering
    {
        static Renderer m_Renderer;
    public:

        static void setRenderingAPI(std::shared_ptr<const RenderingAPI> renderingAPI);

        static std::shared_ptr<const RenderingAPI> getRenderingAPI();

        static void render();
    };
}

#endif
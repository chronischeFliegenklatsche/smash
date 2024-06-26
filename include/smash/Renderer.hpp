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
        std::unique_ptr<RenderingAPI> m_RenderingAPI;
    public:

        Renderer();
        ~Renderer();

        void bindRenderingAPI(std::unique_ptr<RenderingAPI> renderingAPI);

        void render(const Scene* _scene) const;
    };

    class Rendering
    {
        static Renderer m_Renderer;
    public:

        static void bindRenderingAPI(std::unique_ptr<RenderingAPI> renderingAPI);
        
        static void render();

        static void shutdown();
    };
}

#endif
#ifndef _GLFW_RENDERING_API_HPP
#define _GLFW_RENDERING_API_HPP

#include "SmartPointers.hpp"
#include "RenderingAPI.hpp"
#include <GLFW/glfw3.h>
#include "GLBaseAPI.hpp"

namespace smash
{
    class GLRenderingAPI : public RenderingAPI, public GLBaseAPI
    {
        GLuint vao, vbo, shaderProgram;

    public:
        GLRenderingAPI();
        ~GLRenderingAPI() override;

        void drawPixel(int x, int y, uint16_t color) const override;
        void swapFrameBuffers() const override;
    };
}

#endif
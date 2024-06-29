#ifndef _RENDERING_API_HPP
#define _RENDERING_API_HPP

#include <stdint.h>

#include "Canvas.hpp"

namespace smash
{

    class RenderingAPI;

    class RenderingAPI
    {
    public:

        RenderingAPI();
        virtual ~RenderingAPI();

        virtual void drawPixel(int x, int y, uint16_t color) const = 0;
        virtual void drawRect(int x, int y, int w, int h, uint16_t color) const = 0;
        virtual void drawCanvas(const Canvas& _canvas) const = 0;

        virtual size_t getCanvasWidth() const = 0;
        virtual size_t getCanvasHeight() const = 0;

        virtual void swapFrameBuffers() const = 0;
    };
}

#endif
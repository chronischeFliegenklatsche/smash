#ifndef _RENDERING_API_HPP
#define _RENDERING_API_HPP

#include "Integers.hpp"

namespace smash
{

    class RenderingAPI;

    class RenderingAPI
    {
    public:

        RenderingAPI();
        virtual ~RenderingAPI();
        virtual void drawPixel(int x, int y, uint16_t color) const = 0;
        virtual void swapFrameBuffers() const = 0;
    };
}

#endif
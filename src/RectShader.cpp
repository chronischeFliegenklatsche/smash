#include <smash.h>

namespace smash
{
    RectShader::RectShader()
    {
    }

    RectShader::RectShader(const float* x, const float* y, const float* w, const float* h, const Color* color)
        : x(x), y(y), w(w), h(h), color(color)
    {
    }

    void RectShader::fragment(size_t x, size_t y, Color& color) const
    {
        if (x >= *(this->x) && x < *(this->x) + *w && y >= *(this->y) && y < *(this->y) + *h)
        {
            color = *(this->color);
        }
    }
}
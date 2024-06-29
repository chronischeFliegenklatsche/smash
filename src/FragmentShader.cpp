
#include <smash.h>

namespace smash
{
    void FragmentShader::execute(Canvas& _canvas) const
    {
        for (size_t y = 0; y < _canvas.getHeight(); ++y)
        {
            for (size_t x = 0; x < _canvas.getWidth(); ++x)
            {
                Color color = _canvas.getPixel(x, y);
                fragment(x, y, color);
                _canvas.setPixel(x, y, color);
            }
        }
    }

    
}
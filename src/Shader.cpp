#include <smash.h>
#include <smash/sh.hpp>

namespace smash
{
    void Shader::execute(ShaderAttributes& _shattr, Canvas& _canvas) const
    {
        shAccess::setSH(&_shattr);
        shade(_canvas);

    }
    
}
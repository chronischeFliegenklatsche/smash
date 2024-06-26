
#include <smash.h>

namespace smash {

    const char* const ShaderProgramProvider::s_ShaderProgramProviderTypes[] { "RectangleRenderer" };

    ShaderProgramProvider::ShaderProgramProvider()
    {}

    ShaderProgramProvider::~ShaderProgramProvider()
    {}

    bool ShaderProgramProvider::hasShaderProgram(TypeNameProvider* object)
    {
        for (const char* type : s_ShaderProgramProviderTypes)
        {
            if (std::string(type) == object->getTypeName())
            {
                return true;
            }
        }
        return false;
    }

}

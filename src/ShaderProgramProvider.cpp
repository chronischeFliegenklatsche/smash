
#include <smash.h>

namespace smash {

    const std::string ShaderProgramProvider::s_ShaderProgramProviderTypes[] { "RectangleRenderer" };
    

    ShaderProgramProvider::ShaderProgramProvider()
    {}

    ShaderProgramProvider::~ShaderProgramProvider()
    {}

    bool ShaderProgramProvider::hasShaderProgram(TypeNameProvider* object)
    {
        for (const std::string& typeName : s_ShaderProgramProviderTypes)
        {
            if (typeName == object->getTypeName())
            {
                return true;
            }
        }
        return false;
    }

}

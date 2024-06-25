#ifdef _SHADER_PROGRAM_PROVIDER_HPP
#include <smash.h>

namespace smash {

    ShaderProgramProvider::ShaderProgramProvider()
    {}

    ShaderProgramProvider::~ShaderProgramProvider()
    {}

    bool ShaderProgramProvider::hasShaderProgram(TypeNameProvider* object)
    {
        for (const char* type : s_ShaderProgramProverTypes)
        {
            if (std::string(type) == object->getTypeName())
            {
                return true;
            }
        }
        return false;
    }

}
#endif
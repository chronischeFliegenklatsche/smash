#ifndef _SHADER_PROGRAM_PROVIDER_HPP
#define _SHADER_PROGRAM_PROVIDER_HPP

#include "SmartPointers.hpp" 
#include "ShaderProgram.hpp"
#include "String.hpp"
#include "TypeNameProvider.hpp"

namespace smash
{
    class ShaderProgramProvider;

    class ShaderProgramProvider
    {
        static const char* const s_ShaderProgramProviderTypes[];

    public:

        ShaderProgramProvider();
        virtual ~ShaderProgramProvider();
        virtual std::shared_ptr<const ShaderProgram> getShaderProgram() const = 0;

        static bool hasShaderProgram(TypeNameProvider* object);
    };
}

#endif
#ifndef _SHADER_UNIFORMS_HPP
#define _SHADER_UNIFORMS_HPP

#include "ShaderAttributes.hpp"


namespace smash
{
    class ShaderUniforms;

    class ShaderUniforms
    {
        typedef Vector2 vec2;
        static ShaderAttributes m_Uniforms;
    public:

        static void setPointer(const std::string &name, void *pointer);
        static void* getPointer(const std::string &name);

        static void setFloat(const std::string &name, float value);
        static float getFloat(const std::string &name);

        static void setVector(const std::string &name, const vec2 &value);
        static vec2 getVector(const std::string &name);
    };
}

#endif
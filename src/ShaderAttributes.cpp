#ifdef _SHADER_ATTRIBUTES_HPP
#include <smash.h>

namespace smash
{

    ShaderAttributes::ShaderAttributes()
    {}

    void ShaderAttributes::setPointer(const std::string &name, void *pointer)
    {
        m_Pointers[name] = pointer;
    }

    void* ShaderAttributes::getPointer(const std::string &name) const
    {
        return m_Pointers.at(name);
    }

    void ShaderAttributes::setFloat(const std::string &name, float value)
    {
        m_Floats[name] = value;
    }

    float ShaderAttributes::getFloat(const std::string &name) const
    {
        return m_Floats.at(name);
    }

    void ShaderAttributes::setVector(const std::string &name, const vec2 &value)
    {
        m_Vectors[name] = value;
    }

    typedef Vector2 vec2;
    vec2 ShaderAttributes::getVector(const std::string &name) const
    {
        return m_Vectors.at(name);
    }

    
    void ShaderAttributes::setColor(const std::string &name, const col &value)
    {
        m_Colors[name] = value;
    }

    typedef Color col;
    col ShaderAttributes::getColor(const std::string &name) const
    {
        return m_Colors.at(name);
    }

}
#endif
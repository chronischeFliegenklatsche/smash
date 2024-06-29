#include <smash.h>

#include <algorithm>

namespace smash
{
    void ShaderAttributes::setPointer(const std::string& name, void* pointer)
    {
        m_Pointers[name] = pointer;
    }

    void ShaderAttributes::setFloat(const std::string& name, float value)
    {
        m_Floats[name] = value;
    }

    void ShaderAttributes::setVector(const std::string& name, Vector2 value)
    {
        m_Vectors[name] = value;
    }

    void ShaderAttributes::setColor(const std::string& name, Color value)
    {
        m_Colors[name] = value;
    }

    void* ShaderAttributes::getPointer(const std::string& name) const
    {
        auto it = m_Pointers.find(name);
        if (it != m_Pointers.end()) {
            return it->second;
        }
        return nullptr;
    }

    float ShaderAttributes::getFloat(const std::string& name) const
    {
        auto it = m_Floats.find(name);
        if (it != m_Floats.end()) {
            return it->second;
        }
        return 0.0f;
    }

    Vector2 ShaderAttributes::getVector(const std::string& name) const
    {
        auto it = m_Vectors.find(name);
        if (it != m_Vectors.end()) {
            return it->second;
        }
        return Vector2::zero();
    }

    Color ShaderAttributes::getColor(const std::string& name) const
    {
        auto it = m_Colors.find(name);
        if (it != m_Colors.end()) {
            return it->second;
        }
        return Color::black;
    }
}
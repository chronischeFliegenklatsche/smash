#ifndef _SHADER_ATTRIBUTES_HPP
#define _SHADER_ATTRIBUTES_HPP

#include <map>
#include <string>

#include "Vector2.hpp"
#include "Color.hpp"

namespace smash
{
    class ShaderAttributes
    {
        std::map<std::string, void*> m_Pointers;
        std::map<std::string, float> m_Floats;
        std::map<std::string, Vector2> m_Vectors;
        std::map<std::string, Color> m_Colors;
    public:

        ShaderAttributes() = default;
        ~ShaderAttributes() = default;

        void setPointer(const std::string& name, void* pointer);
        void setFloat(const std::string& name, float value);
        void setVector(const std::string& name, Vector2 value);
        void setColor(const std::string& name, Color value);

        void* getPointer(const std::string& name) const;
        float getFloat(const std::string& name) const;
        Vector2 getVector(const std::string& name) const;
        Color getColor(const std::string& name) const;

    };
}   

#endif
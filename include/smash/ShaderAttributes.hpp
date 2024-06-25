#ifndef _SHAADER_ATTRIBUTES_HPP
#define _SHAADER_ATTRIBUTES_HPP

#include "Containers.hpp"
#include "Vector2.hpp"
#include "Color.hpp"
#include "String.hpp"

namespace smash
{
    class ShaderAttributes
    {
        typedef Vector2 vec2;
        typedef Color col;
        std::map<std::string, void*> m_Pointers;
        std::map<std::string, float> m_Floats;
        std::map<std::string, vec2> m_Vectors;
        std::map<std::string, col> m_Colors;
        
    public:

        ShaderAttributes();

        void setPointer(const std::string &name, void *pointer);
        void* getPointer(const std::string &name) const;

        void setFloat(const std::string &name, float value);
        float getFloat(const std::string &name) const;

        void setVector(const std::string &name, const vec2 &value);
        vec2 getVector(const std::string &name) const;

        void setColor(const std::string &name, const col &value);
        col getColor(const std::string &name) const;

    };
}

#endif
#ifndef _SH_HPP
#define _SH_HPP

#include <string>
#include "ShaderAttributes.hpp"

namespace smash {
    class Shader;  // Forward declaration
}

class shAccess
{
    friend class smash::Shader;
    static void setSH(smash::ShaderAttributes* _sh);
};

// Function declarations
void* gp(const std::string& _name);
float gf(const std::string& _name);
smash::Vector2 gv(const std::string& _name);
smash::Color gc(const std::string& _name);

void sp(const std::string& _name, void* _pointer);
void sf(const std::string& _name, float _value);
void sv(const std::string& _name, const smash::Vector2& _value);
void sc(const std::string& _name, const smash::Color& _value);

#endif
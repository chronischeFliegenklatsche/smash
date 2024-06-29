#include <smash/sh.hpp>

static smash::ShaderAttributes* _SHATTR = nullptr;

void shAccess::setSH(smash::ShaderAttributes* _sh)
{
    _SHATTR = _sh;
}

void* gp(const std::string& _name)
{
    return _SHATTR->getPointer(_name);
}

float gf(const std::string& _name)
{
    return _SHATTR->getFloat(_name);
}

smash::Vector2 gv(const std::string& _name)
{
    return _SHATTR->getVector(_name);
}

smash::Color gc(const std::string& _name)
{
    return _SHATTR->getColor(_name);
}

void sp(const std::string& _name, void* _pointer)
{
    _SHATTR->setPointer(_name, _pointer);
}

void sf(const std::string& _name, float _value)
{
    _SHATTR->setFloat(_name, _value);
}

void sv(const std::string& _name, const smash::Vector2& _value)
{
    _SHATTR->setVector(_name, _value);
}

void sc(const std::string& _name, const smash::Color& _value)
{
    _SHATTR->setColor(_name, _value);
}

#include <smash.h>

namespace smash {

    ShaderAttributes ShaderUniforms::m_Uniforms;

    void ShaderUniforms::setPointer(const std::string& name, void* pointer) {
        m_Uniforms.setPointer(name, pointer);
    }

    void* ShaderUniforms::getPointer(const std::string& name) {
        return m_Uniforms.getPointer(name);
    }

    void ShaderUniforms::setFloat(const std::string& name, float value) {
        m_Uniforms.setFloat(name, value);
    }

    float ShaderUniforms::getFloat(const std::string& name) {
        return m_Uniforms.getFloat(name);
    }

    void ShaderUniforms::setVector(const std::string& name, const vec2& value) {
        m_Uniforms.setVector(name, value);
    }

    typedef Vector2 vec2;
    vec2 ShaderUniforms::getVector(const std::string& name) {
        return m_Uniforms.getVector(name);
    }

}

#ifdef _SHADER_PROGRAM_HPP
#include <smash.h>

namespace smash {

    ShaderProgram::ShaderProgram()
        : m_Attributes(std::make_shared<ShaderAttributes>()) {}

    void ShaderProgram::addShader(const std::shared_ptr<const Shader>& shader) {
        m_Shaders.push_back(shader);
    }

    bool ShaderProgram::removeShader(const std::shared_ptr<const Shader>& shader) {
        for (auto it = m_Shaders.begin(); it != m_Shaders.end(); ++it) {
            if (*it == shader) {
                m_Shaders.erase(it);
                return true;
            }
        }
        return false;
    }       

    void ShaderProgram::setAttributes(const std::shared_ptr<ShaderAttributes>& attributes) {
        m_Attributes = attributes;
    }

    std::shared_ptr<ShaderAttributes> ShaderProgram::getAttributes() const {
        return m_Attributes;
    }

    void ShaderProgram::execute(const RenderingAPI* _renderAPI) const {
        for (const auto& shader : m_Shaders) {
            shader->shade(*m_Attributes, _renderAPI);
        }
    }

}
#endif
#ifndef _SHADER_PROGRAM_HPP
#define _SHADER_PROGRAM_HPP

#include "Containers.hpp"
#include "SmartPointers.hpp"
#include "Shader.hpp"
#include "ShaderAttributes.hpp"

namespace smash
{
    class ShaderProgram;

    class ShaderProgram
    {
        std::vector<std::shared_ptr<const Shader>> m_Shaders;
        mutable std::shared_ptr<ShaderAttributes> m_Attributes;
    public:

        ShaderProgram();

        void addShader(const std::shared_ptr<const Shader> &shader);
        bool removeShader(const std::shared_ptr<const Shader> &shader); 

        void setAttributes(const std::shared_ptr<ShaderAttributes> &attributes);
        std::shared_ptr<ShaderAttributes> getAttributes() const;

        void execute(const RenderingAPI* _renderAPI) const; 

    };
}

#endif
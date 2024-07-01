#ifndef _SHADER_RENDERER_HPP
#define _SHADER_RENDERER_HPP

#include "Component.hpp"
#include "ShaderProgram.hpp"

namespace smash
{
    class ShaderRenderer : public Component
    {
        std::unique_ptr<ShaderAttributes> m_ShaderAttributes;
        ShaderProgram m_ShaderProgram;
    public:
        ShaderRenderer() = default;
        ShaderRenderer(int updateIndex) : Component(updateIndex) {}
        virtual ~ShaderRenderer() = default;
        virtual std::unique_ptr<Component> clone() const override;
        virtual void render(const RenderingAPI& _renderingAPI) const override;
        virtual std::string getTypeName() const override;

        void bindShaderAttributes(std::unique_ptr<ShaderAttributes> _shaderAttributes);

        void bind(std::unique_ptr<const Shader> _shader);
        bool swap(int i1, int i2);
    };
}


#endif
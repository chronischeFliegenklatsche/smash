#ifndef _SHADER_RENDERER_HPP
#define _SHADER_RENDERER_HPP

#include "Component.hpp"
#include "ShaderProgram.hpp"

namespace smash
{
    class ShaderRenderer : public Component
    {
        std::unique_ptr<ShaderAttributes> m_StartFrameShaderAttributes;
        ShaderProgram m_ShaderProgram;
    public:
        ShaderRenderer() = default;
        ShaderRenderer(int updateIndex) : Component(updateIndex) {}
        virtual ~ShaderRenderer() = default;
        virtual Component* clone() const override;
        virtual void update() override;
        virtual void render(const RenderingAPI& _renderingAPI) const override;
        virtual std::string getTypeName() const override;

        void bindStartFrameShaderAttributes(std::unique_ptr<ShaderAttributes> _shaderAttributes);

        void bind(std::unique_ptr<const Shader> _shader);
        bool swap(int i1, int i2);
    };
}


#endif
#ifndef _FRAGMENT_SHADER_PASS_HPP
#define _FRAGMENT_SHADER_PASS_HPP

#include <memory>

#include "Component.hpp"
#include "FragmentShader.hpp"

namespace smash
{
    class FragmentShaderPass : public Component
    {
    private:
        class FragmentShaderNode
        {
        public:
            std::unique_ptr<const FragmentShader> shader;
            FragmentShaderNode* next;

            FragmentShaderNode(std::unique_ptr<const FragmentShader> s) : shader(std::move(s)), next(nullptr) {}
        };

        FragmentShaderNode* m_Head;
        int m_Size;

    public:
        FragmentShaderPass();
        virtual ~FragmentShaderPass();

        int bind(std::unique_ptr<const FragmentShader> fragmentShader);
        bool swap(int i1, int i2);

        void update() override {}
        void render(const RenderingAPI& _renderingAPI) const override;
        std::string getTypeName() const override { return "FragmentShaderPass"; }
        Component* clone() const override { return new FragmentShaderPass(); } 

    private:
        FragmentShaderNode* getNodeAt(int index) const;
        bool isValidIndex(int index) const;
    };
}

#endif
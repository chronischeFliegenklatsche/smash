#ifndef _SHADER_PROGRAM_HPP
#define _SHADER_PROGRAM_HPP

#include <memory>

#include "Shader.hpp"
#include "RenderingAPI.hpp"

namespace smash
{
    class ShaderProgram
    {
    private:
        class ShaderNode
        {
        public:
            std::unique_ptr<const Shader> shader;
            ShaderNode* next;

            ShaderNode(std::unique_ptr<const Shader> s) : shader(std::move(s)), next(nullptr) {}
        };

        ShaderNode* m_Head;
        int m_Size;

    public:

        ShaderProgram();
        virtual ~ShaderProgram();

        int bind(std::unique_ptr<const Shader> shader);
        bool swap(int i1, int i2);

        void use(const ShaderAttributes& frameStart_shattr, const RenderingAPI& _renderingAPI) const;

    private:
        ShaderNode* getNodeAt(int index) const;
        bool isValidIndex(int index) const;
    };
}

#endif
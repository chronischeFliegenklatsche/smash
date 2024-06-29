#include <smash.h>

namespace smash
{
    ShaderProgram::ShaderProgram() : m_Head(nullptr), m_Size(0) {}

    ShaderProgram::~ShaderProgram()
    {
        while (m_Head)
        {
            ShaderNode* temp = m_Head;
            m_Head = m_Head->next;
            delete temp;
        }
    }

    int ShaderProgram::bind(std::unique_ptr<const Shader> shader)
    {
        ShaderNode* newNode = new ShaderNode(std::move(shader));
        
        int newIndex = 0;
        if (!m_Head)
        {
            m_Head = newNode;
        }
        else
        {
            ShaderNode* current = m_Head;
            while (current->next)
            {
                current = current->next;
                newIndex++;
            }
            current->next = newNode;
            newIndex++;
        }

        m_Size++;
        return newIndex;
    }

    bool ShaderProgram::swap(int i1, int i2)
    {
        if (i1 == i2) return true;
        if (!isValidIndex(i1) || !isValidIndex(i2)) return false;

        ShaderNode* node1 = getNodeAt(i1);
        ShaderNode* node2 = getNodeAt(i2);

        if (node1 && node2)
        {
            std::swap(node1->shader, node2->shader);
            return true;
        }

        return false;
    }

    ShaderProgram::ShaderNode* ShaderProgram::getNodeAt(int index) const
    {
        if (!isValidIndex(index)) return nullptr;

        ShaderNode* current = m_Head;
        for (int i = 0; i < index; ++i)
        {
            current = current->next;
        }
        return current;
    }

    bool ShaderProgram::isValidIndex(int index) const
    {
        return (index >= 0 && index < m_Size);
    }

    void ShaderProgram::use(const ShaderAttributes& frameStart_shattr, const RenderingAPI& _renderingAPI) const
    {
        ShaderAttributes shattr = frameStart_shattr;
        Canvas canvas(_renderingAPI.getCanvasWidth(), _renderingAPI.getCanvasHeight());
        ShaderNode* current = m_Head;
        while (current)
        {
            current->shader->execute(shattr, canvas);
            current = current->next;
        }
        _renderingAPI.drawCanvas(canvas);
    }

    void ShaderRenderer::bind(std::unique_ptr<const Shader> _shader)
    {
        m_ShaderProgram.bind(std::move(_shader));
    }

    bool ShaderRenderer::swap(int i1, int i2)
    {
        return m_ShaderProgram.swap(i1, i2);
    }
}
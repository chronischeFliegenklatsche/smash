#include <smash.h>

namespace smash
{
    FragmentShaderPass::FragmentShaderPass() : m_Head(nullptr), m_Size(0) {}

    FragmentShaderPass::~FragmentShaderPass()
    {
        while (m_Head)
        {
            FragmentShaderNode* temp = m_Head;
            m_Head = m_Head->next;
            delete temp;
        }
    }

    int FragmentShaderPass::bind(std::unique_ptr<const FragmentShader> fragmentShader)
    {
        FragmentShaderNode* newNode = new FragmentShaderNode(std::move(fragmentShader));
        
        int newIndex = 0;
        if (!m_Head)
        {
            m_Head = newNode;
        }
        else
        {
            FragmentShaderNode* current = m_Head;
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

    bool FragmentShaderPass::swap(int i1, int i2)
    {
        if (i1 == i2) return true;
        if (!isValidIndex(i1) || !isValidIndex(i2)) return false;

        FragmentShaderNode* node1 = getNodeAt(i1);
        FragmentShaderNode* node2 = getNodeAt(i2);

        if (node1 && node2)
        {
            std::swap(node1->shader, node2->shader);
            return true;
        }

        return false;
    }

    FragmentShaderPass::FragmentShaderNode* FragmentShaderPass::getNodeAt(int index) const
    {
        if (!isValidIndex(index)) return nullptr;

        FragmentShaderNode* current = m_Head;
        for (int i = 0; i < index; ++i)
        {
            current = current->next;
        }
        return current;
    }

    bool FragmentShaderPass::isValidIndex(int index) const
    {
        return (index >= 0 && index < m_Size);
    }

    void FragmentShaderPass::render(const RenderingAPI& _renderingAPI) const
    {
        Canvas canvas(_renderingAPI.getCanvasWidth(), _renderingAPI.getCanvasHeight());
        FragmentShaderNode* current = m_Head;
        while (current)
        {
            current->shader->execute(canvas);
            current = current->next;
        }
        _renderingAPI.drawCanvas(canvas);
        
    }
}
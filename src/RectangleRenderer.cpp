#ifdef _RECTANGLE_RENDERER_HPP
#include <smash.h>

namespace smash {

    RectangleRenderer::RectangleRenderer()
        : m_Color(), m_Size(Vector2(1.0f, 1.0f)), m_ShaderProgram(nullptr) {
            createShaderProgram();
        }

    RectangleRenderer::RectangleRenderer(Vector2 size)
        : m_Color(), m_Size(size), m_ShaderProgram(nullptr) {
            createShaderProgram();
        }

    RectangleRenderer::RectangleRenderer(float width, float height)
        : m_Color(), m_Size(Vector2(width, height)), m_ShaderProgram(nullptr) {
            createShaderProgram();
        }

    RectangleRenderer::RectangleRenderer(Vector2 size, Color color)
        : m_Color(color), m_Size(size), m_ShaderProgram(nullptr) {
            createShaderProgram();
        }

    RectangleRenderer::RectangleRenderer(float width, float height, Color color)
        : m_Color(color), m_Size(Vector2(width, height)), m_ShaderProgram(nullptr) {
            createShaderProgram();
        }

    void RectangleRenderer::setSize(Vector2 size) {
        m_Size = size;
        m_ShaderProgram->getAttributes()->setVector("m_Size", m_Size);
    }

    Vector2 RectangleRenderer::getSize() {
        return m_Size;
    }

    void RectangleRenderer::setColor(Color color) {
        m_Color = color;
        m_ShaderProgram->getAttributes()->setColor("m_Color", Color(m_Color));
    }

    Color RectangleRenderer::getColor() {
        return m_Color;
    }

    std::shared_ptr<const ShaderProgram> RectangleRenderer::getShaderProgram() const {
        return m_ShaderProgram;
    }

    Component* RectangleRenderer::clone() const {
        return new RectangleRenderer(*this);
    }

    void RectangleRenderer::update() {
        // Implement any update logic here
        GameObject *gameObject = getGameObject();
        if (gameObject)
        {
            const Transform *transform = nullptr;
#ifdef _WIN32
            transform = gameObject->getComponent<Transform>().get();
#endif
#ifdef ARDUINO
            transform = (Transform*)gameObject->getComponent("Transform").get();
#endif
            if (transform)
            {
                m_ShaderProgram->getAttributes()->setVector("m_Position", transform->getPosition());
            }
        }
    }
    
    void RectangleRenderer::createShaderProgram() {
        // Implement shader program creation here
        m_ShaderProgram = std::make_shared<ShaderProgram>();
        m_ShaderProgram->addShader(std::shared_ptr<Shader>(new RectangleShader()));
        std::shared_ptr<ShaderAttributes> attributes = std::make_shared<ShaderAttributes>();
        GameObject *gameObject = getGameObject();
        if (gameObject)
        {
            const Transform *transform = nullptr;
#ifdef _WIN32
            transform = gameObject->getComponent<Transform>().get();
#endif
#ifdef ARDUINO
            transform = (Transform*)gameObject->getComponent("Transform").get();
#endif
            if (transform)
            {
                attributes->setVector("m_Position", transform->getPosition());
            }
        }
        attributes->setVector("m_Size", m_Size);
        attributes->setColor("m_Color", Color(m_Color));
        m_ShaderProgram->setAttributes(attributes);
    }

    std::string RectangleRenderer::getTypeName() const {
        return "RectangleRenderer";
    }
}
#endif
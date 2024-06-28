
#include <smash.h>

namespace smash {

    RectangleRenderer::RectangleRenderer()
        : m_Color(), m_Size(Vector2(1.0f, 1.0f)) {
            
        }

    RectangleRenderer::RectangleRenderer(Vector2 size)
        : m_Color(), m_Size(size) {
            
        }

    RectangleRenderer::RectangleRenderer(float width, float height)
        : m_Color(), m_Size(Vector2(width, height)) {
            
        }

    RectangleRenderer::RectangleRenderer(Vector2 size, Color color)
        : m_Color(color), m_Size(size) {
            
        }

    RectangleRenderer::RectangleRenderer(float width, float height, Color color)
        : m_Color(color), m_Size(Vector2(width, height)) {
            
        }

    void RectangleRenderer::setSize(Vector2 size) {
        m_Size = size;
    }

    Vector2 RectangleRenderer::getSize() {
        return m_Size;
    }

    void RectangleRenderer::setColor(Color color) {
        m_Color = color;
    }

    Color RectangleRenderer::getColor() {
        return m_Color;
    }


    Component* RectangleRenderer::clone() const {
        return new RectangleRenderer(*this);
    }

    void RectangleRenderer::update() {

    }
    

    std::string RectangleRenderer::getTypeName() const {
        return "RectangleRenderer";
    }

    void RectangleRenderer::render(const RenderingAPI* renderingAPI) const {
        
        if (getGameObject())
        {
            Transform* transform = (Transform*)getGameObject()->getComponent("Transform").get();
            if (transform)
            {
                renderingAPI->drawRect((int)transform->getPosition().x, (int)transform->getPosition().y, (int)m_Size.x, (int)m_Size.y, m_Color.getRGB16());
            }
            
        }

    }
}

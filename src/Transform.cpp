
#include <smash.h>

namespace smash {

    Transform::Transform()
        : m_Position(0.0f, 0.0f) {}

    Transform::Transform(Vector2 position)
        : m_Position(position) {}

    Transform::Transform(float x, float y)
        : m_Position(x, y) {}

    Transform::Transform(Vector2 position, Vector2 scale)
        : m_Position(position), m_Scale(scale) {}

    Transform::Transform(float x, float y, float width, float height)
        : m_Position(x, y), m_Scale(width, height) {}   

    void Transform::translate(Vector2 translation) {
        m_Position += translation;
    }

    void Transform::setPosition(Vector2 position) {
        m_Position = position;
    }

    Vector2 Transform::getPosition() const {
        return m_Position;
    }

    Vector2& Transform::getPositionRef() {
        return m_Position;
    }

    void Transform::setScale(Vector2 scale) {
        m_Scale = scale;
    }

    Vector2 Transform::getScale() const {
        return m_Scale;
    }

    Vector2& Transform::getScaleRef() {
        return m_Scale;
    }

    Component* Transform::clone() const {
        Transform *clone = new Transform();
        clone->m_Position = m_Position;
        clone->m_Scale = m_Scale;
        return clone;
    }

    void Transform::update()
    {}

    std::string Transform::getTypeName() const {
        return "Transform";
    }

}

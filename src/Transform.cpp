#include <smash.h>

namespace smash {

    Transform::Transform()
        : m_Position(0.0f, 0.0f) {}

    Transform::Transform(Vector2 position)
        : m_Position(position) {}

    Transform::Transform(float x, float y)
        : m_Position(x, y) {}

    void Transform::translate(Vector2 translation) {
        m_Position += translation;
    }

    void Transform::setPosition(Vector2 position) {
        m_Position = position;
    }

    Vector2 Transform::getPosition() const {
        return m_Position;
    }

    Component* Transform::clone() const {
        Transform *clone = new Transform();
        clone->m_Position = m_Position;
        return clone;
    }

    void Transform::update()
    {}

    std::string Transform::getTypeName() const {
        return "Transform";
    }

}
#ifndef _TRANSFORM_HPP
#define _TRANSFORM_HPP

#include "Component.hpp"
#include "Vector2.hpp"

namespace smash
{
    class Transform;

    class Transform : public Component
    {
        Vector2 m_Position;
        Vector2 m_Scale;
    public:

        Transform();
        Transform(Vector2 position);
        Transform(float x, float y);
        Transform(Vector2 position, Vector2 scale);
        Transform(float x, float y, float scaleX, float scaleY);

        void translate(Vector2 translation);
        void setPosition(Vector2 position);
        Vector2 getPosition() const;

        Component* clone() const override;
        void update() override;

        std::string getTypeName() const override;
    };
}

#endif
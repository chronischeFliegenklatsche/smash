#ifndef _RECTANGLE_RENDERER_HPP
#define _RECTANGLE_RENDERER_HPP

#include "SmartPointers.hpp"
#include "Component.hpp"
#include "Vector2.hpp"
#include "Color.hpp"

namespace smash
{
    class RectangleRenderer : public Component
    {
        Color m_Color;
        Vector2 m_Size;
    public:

        RectangleRenderer();
        RectangleRenderer(Vector2 size);
        RectangleRenderer(float width, float height);
        RectangleRenderer(Vector2 size, Color color);
        RectangleRenderer(float width, float height, Color color);

        void setSize(Vector2 size);
        Vector2 getSize();

        void setColor(Color color);
        Color getColor();

        Component* clone() const override;
        void update() override;
        void render(const RenderingAPI* renderingAPI) const override;

        std::string getTypeName() const override;
    };
}

#endif
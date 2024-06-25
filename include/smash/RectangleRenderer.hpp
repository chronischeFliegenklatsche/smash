#ifndef _RECTANGLE_RENDERER_HPP
#define _RECTANGLE_RENDERER_HPP

#include "SmartPointers.hpp"
#include "Component.hpp"
#include "ShaderProgramProvider.hpp"
#include "Vector2.hpp"
#include "Color.hpp"

namespace smash
{
    class RectangleRenderer : public Component, public ShaderProgramProvider
    {
        Color m_Color;
        Vector2 m_Size;
        std::shared_ptr<ShaderProgram> m_ShaderProgram;

        void createShaderProgram();

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

        std::shared_ptr<const ShaderProgram> getShaderProgram() const override;

        Component* clone() const override;
        void update() override;

        std::string getTypeName() const override;
    };
}

#endif
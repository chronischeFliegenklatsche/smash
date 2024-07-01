#ifndef _COMPONENT_HPP
#define _COMPONENT_HPP

#include "GameObject.hpp"
#include "TypeNameProvider.hpp"
#include "RenderingAPI.hpp"
#include <memory>

namespace smash
{
    class Component;

    class Component : public TypeNameProvider
    {
        friend class GameObject;
        friend class ComponentsContainer;
        const int _updateIndex;
        GameObject *_gameObject;
    public:
        Component();
        Component(int updateIndex);

        GameObject* getGameObject() const;
        virtual ~Component();

        virtual std::string getTypeName() const = 0;
        virtual std::unique_ptr<Component> clone() const = 0;

        virtual void update();
        virtual void render(const RenderingAPI& _renderingAPI) const;
    };
}

#endif
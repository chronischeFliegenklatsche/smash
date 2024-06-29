#ifndef _GAME_OBJECT_HPP
#define _GAME_OBJECT_HPP

#include <memory>
#include <vector>

namespace smash
{

    class GameObject;
    class Component;
    class Scene;

    class GameObject
    {
        friend class Scene;
        Scene *_scene;
        std::vector<std::shared_ptr<Component>> _components;
    public:

        GameObject();
        virtual ~GameObject();

        Scene* getScene() const;

        void addComponent(std::shared_ptr<Component> component);
        bool removeComponent(std::shared_ptr<Component> component);

#ifdef _WIN32
        template<typename T>
        std::shared_ptr<T> getComponent();

        template<typename T>
        const std::shared_ptr<T> getComponent() const;
#endif

    std::shared_ptr<Component> getComponent(const std::string& typeName);
    std::shared_ptr<const Component> getComponent(const std::string& typeName) const;

    };
}

#endif
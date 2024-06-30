
#include <smash.h>

namespace smash
{
    GameObject::GameObject() : _scene(nullptr), _components()
    {}

    GameObject::~GameObject()
    {}
 
    void GameObject::addComponent(std::shared_ptr<Component> component)
    {
        _components.push_back(component);
        component->_gameObject = this;
        
        if (_scene != nullptr)
        {
            _scene->_components.addComponent(*component);
        }
    }

    bool GameObject::removeComponent(std::shared_ptr<Component> component)
    {
        for (auto itr = _components.begin(); itr != _components.end(); ++itr)
        {
            if (*itr == component)
            {
                _components.erase(itr);
                component.get()->_gameObject = nullptr;

                if (_scene != nullptr)
                    _scene->_components.removeComponent(*component);

                return true;
            }
        }
        return false;
    }

#ifdef _WIN32
    template<typename T>
    std::shared_ptr<T> GameObject::getComponent()
    {
        for (auto& component : _components)
        {
            T* typeComponent = dynamic_cast<T*>(component.get());
            if (typeComponent)
            {
                return std::dynamic_pointer_cast<T>(component);
            }
        }
        return nullptr;
    }



    template<typename T>
    const std::shared_ptr<T> GameObject::getComponent() const
    {
        for (auto& component : _components)
        {
            T* typeComponent = dynamic_cast<T*>(component.get());
            if (typeComponent)
            {
                return std::dynamic_pointer_cast<T>(component);
            }
        }
        return nullptr;
    }

    // implement the get Scene function
    Scene* GameObject::getScene() const
    {
        return _scene;
    }
    
    template std::shared_ptr<Transform> GameObject::getComponent<Transform>();
    template const std::shared_ptr<Transform> GameObject::getComponent<Transform>() const;

#endif

    std::shared_ptr<Component> GameObject::getComponent(const std::string& typeName)
    {
        for (auto& component : _components)
        {
            if (component->getTypeName() == typeName)
            {
                return component;
            }
        }
        return nullptr;
    }

    std::shared_ptr<const Component> GameObject::getComponent(const std::string& typeName) const
    {
        for (auto& component : _components)
        {
            if (component->getTypeName() == typeName)
            {
                return component;
            }
        }
        return nullptr;
    }
}

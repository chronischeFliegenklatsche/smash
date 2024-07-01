
#include <smash.h>

namespace smash
{
    GameObject::GameObject() : m_Scene(), m_Components()
    {}

    GameObject::~GameObject()
    {}
 
    void GameObject::addComponent(std::shared_ptr<Component> component)
    {
        m_Components.push_back(component);
        component->_gameObject = this;
        
        if (m_Scene)
        {
            m_Scene->m_Components.addComponent(*component);
        }
    }

    bool GameObject::removeComponent(std::weak_ptr<Component> component)
    {
        for (auto itr = m_Components.begin(); itr != m_Components.end(); ++itr)
        {
            if (auto c = component.lock(); c == *itr)
            {
                m_Components.erase(itr);
                c.get()->_gameObject = nullptr;

                if (m_Scene)
                    m_Scene->m_Components.removeComponent(*c);

                return true;
            }
        }
        return false;
    }

#ifdef _WIN32
    template<typename T>
    std::weak_ptr<T> GameObject::getComponent()
    {
        for (auto& component : m_Components)
        {
            T* typeComponent = dynamic_cast<T*>(component.get());
            if (typeComponent)
            {
                return std::dynamic_pointer_cast<T>(component);
            }
        }
        return std::weak_ptr<T>();
    }



    template<typename T>
    const std::weak_ptr<T> GameObject::getComponent() const
    {
        for (auto& component : m_Components)
        {
            T* typeComponent = dynamic_cast<T*>(component.get());
            if (typeComponent)
            {
                return std::dynamic_pointer_cast<T>(component);
            }
        }
        return std::weak_ptr<T>();
    }

    // implement the get Scene function
    Scene* GameObject::getScene() const
    {
        return m_Scene;
    }
    
    template std::weak_ptr<Transform> GameObject::getComponent<Transform>();
    template const std::weak_ptr<Transform> GameObject::getComponent<Transform>() const;

#endif

    std::weak_ptr<Component> GameObject::getComponent(const std::string& typeName)
    {
        for (auto& component : m_Components)
        {
            if (component->getTypeName() == typeName)
            {
                return component;
            }
        }
        return std::weak_ptr<Component>();
    }

    std::weak_ptr<const Component> GameObject::getComponent(const std::string& typeName) const
    {
        for (auto& component : m_Components)
        {
            if (component->getTypeName() == typeName)
            {
                return component;
            }
        }
        return std::weak_ptr<const Component>();
    }
}

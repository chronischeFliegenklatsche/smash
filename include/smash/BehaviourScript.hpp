#ifndef _BEHAVIOUR_SCRIPT_HPP
#define _BEHAVIOUR_SCRIPT_HPP

#include "SmartPointers.hpp"
#include "Component.hpp"
#include "GameObject.hpp"
#include "Scene.hpp"

namespace smash {

    class BehaviourScript;

    class BehaviourScript : public Component {

    public:
        BehaviourScript();
        BehaviourScript(int updateIndex);
        virtual ~BehaviourScript();

        void addComponent(std::shared_ptr<Component> component) const;
        bool removeComponent(std::shared_ptr<Component> component) const;

#ifdef _WIN32
        template<typename T>
        std::shared_ptr<T> getComponent() const {
            return getGameObject()->getComponent<T>();
        }
#endif

        std::shared_ptr<Component> getComponent(const std::string& typeName);

        void instantiate(std::shared_ptr<GameObject> gameObject) const;
        bool destroy(std::shared_ptr<GameObject> gameObject) const;

        void setActiveScene(std::shared_ptr<Scene> scene) const;

        Scene* getActiveScene() const;
    };
}

#endif
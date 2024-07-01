#ifndef _BEHAVIOUR_SCRIPT_HPP
#define _BEHAVIOUR_SCRIPT_HPP

#include <memory>

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
        bool removeComponent(std::weak_ptr<Component> component) const;

#ifdef _WIN32
        template<typename T>
        std::weak_ptr<T> getComponent() const {
            if (getGameObject()) {
                return getGameObject()->getComponent<T>();
            }
            return std::weak_ptr<T>();
        }
#endif

        std::weak_ptr<Component> getComponent(const std::string& typeName);

        void instantiate(std::shared_ptr<GameObject> gameObject) const;
        bool destroy(std::shared_ptr<GameObject> gameObject) const;

        void setActiveScene(const Scene& scene) const;

        Scene* getActiveScene() const;
    };
}

#endif
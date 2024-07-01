
#include <smash.h>

namespace smash {

    BehaviourScript::BehaviourScript() {
    }

    BehaviourScript::BehaviourScript(int updateIndex) : Component(updateIndex) {
    }

    BehaviourScript::~BehaviourScript() {
    }

    void BehaviourScript::addComponent(std::shared_ptr<Component> component) const {
        if (getGameObject())
        {
            getGameObject()->addComponent(component);
        }
    }

    bool BehaviourScript::removeComponent(std::weak_ptr<Component> component) const {
        if (getGameObject())
        {
            return getGameObject()->removeComponent(component);
        }
        return false;
    }

    void BehaviourScript::instantiate(std::shared_ptr<GameObject> gameObject) const {
        if (getGameObject() && getGameObject()->getScene())
        {
            getGameObject()->getScene()->instantiate(gameObject);
        }
    }

    bool BehaviourScript::destroy(std::shared_ptr<GameObject> gameObject) const {
        if (getGameObject() && getGameObject()->getScene())
        {
            return getGameObject()->getScene()->destroy(gameObject);
        }
        return false;
    }

    void BehaviourScript::setActiveScene(const Scene& scene) const {
        SceneManagement::setActiveScene(scene);
    }

    Scene* BehaviourScript::getActiveScene() const {
        return SceneManagement::getActiveScene();
    }

    std::weak_ptr<Component> BehaviourScript::getComponent(const std::string& typeName) {
        if (getGameObject())
        {
            return getGameObject()->getComponent(typeName).lock();
        }
        return std::weak_ptr<Component>();
    }
}

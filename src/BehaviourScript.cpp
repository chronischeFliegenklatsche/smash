
#include <smash.h>

namespace smash {

    BehaviourScript::BehaviourScript() {
    }

    BehaviourScript::BehaviourScript(int updateIndex) : Component(updateIndex) {
    }

    BehaviourScript::~BehaviourScript() {
    }

    void BehaviourScript::addComponent(std::shared_ptr<Component> component) const {
        getGameObject()->addComponent(component);
    }

    bool BehaviourScript::removeComponent(std::shared_ptr<Component> component) const {
        return getGameObject()->removeComponent(component);
    }

    void BehaviourScript::instantiate(std::shared_ptr<GameObject> gameObject) const {
        getGameObject()->getScene()->instantiate(gameObject);
    }

    bool BehaviourScript::destroy(std::shared_ptr<GameObject> gameObject) const {
        return getGameObject()->getScene()->destroy(gameObject);
    }

    void BehaviourScript::setActiveScene(std::shared_ptr<Scene> scene) const {
        SceneManagement::setActiveScene(scene);
    }

    Scene* BehaviourScript::getActiveScene() const {
        return SceneManagement::getActiveScene();
    }

    std::shared_ptr<Component> BehaviourScript::getComponent(const std::string& typeName) {
        return getGameObject()->getComponent(typeName);
    }
}


#include <smash.h>

namespace smash
{
    Scene::Scene()
    {}

    Scene::~Scene()
    {}

    void Scene::instantiate(std::shared_ptr<GameObject> gameObject)
    {
        _gameObjects.push_back(gameObject);
        
        for (auto& component : gameObject.get()->m_Components)
        {
            m_Components.addComponent(*component);
        }
        
        gameObject.get()->m_Scene = this;
    }

    bool Scene::destroy(std::weak_ptr<GameObject> gameObject)
    {
        for (auto itr = _gameObjects.begin(); itr != _gameObjects.end(); ++itr)
        {
            if (auto gm = gameObject.lock(); *itr == gm)
            {
                _gameObjects.erase(itr);

                for (auto& component : gm->m_Components)
                {
                    m_Components.removeComponent(*component);
                }

                gm->m_Scene = nullptr;
                return true;
            }
        }
        return false;
    }

    void Scene::update()
    {
        for (Component& component : m_Components)
        {
            component.update();
        }
    }   
}

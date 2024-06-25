#ifdef _SCENE_HPP
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
        
        for (auto& component : gameObject.get()->_components)
        {
            _components.addComponent(*component);
        }

        gameObject.get()->_scene = this;
    }

    bool Scene::destroy(std::shared_ptr<GameObject> gameObject)
    {
        for (auto itr = _gameObjects.begin(); itr != _gameObjects.end(); ++itr)
        {
            if (*itr == gameObject)
            {
                _gameObjects.erase(itr);

                for (auto& component : gameObject.get()->_components)
                {
                    _components.removeComponent(*component);
                }

                gameObject.get()->_scene = nullptr;
                return true;
            }
        }
        return false;
    }

    void Scene::update()
    {
        for (Component& component : _components)
        {
            component.update();
        }
    }   
}
#endif
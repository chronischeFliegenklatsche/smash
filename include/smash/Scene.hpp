#ifndef _SCENE_HPP
#define _SCENE_HPP

#include <memory>
#include <vector>

#include "ComponentsContainer.hpp"  

namespace smash
{
    class Scene;

    class Scene
    {
        friend class Renderer;
        friend class GameObject;
        ComponentsContainer m_Components;
        std::vector<std::shared_ptr<GameObject>> _gameObjects;
    public:
    
        Scene();
        virtual ~Scene();

        void instantiate(std::shared_ptr<GameObject> gameObject);   
        bool destroy(std::weak_ptr<GameObject> gameObject);
        
        virtual void update();

    };
}


#endif
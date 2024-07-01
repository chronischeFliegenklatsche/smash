#ifndef _SCENE_MANAGEMENT_HPP
#define _SCENE_MANAGEMENT_HPP


#include <memory>
#include <vector>

#include "Scene.hpp"

namespace smash
{
    class SceneManager;
    class SceneManagement;

    class SceneManager
    {
        std::vector<std::shared_ptr<Scene>> m_Scenes;
        Scene *m_ActiveScene;
    public:

        SceneManager();

        void addScene(std::shared_ptr<Scene> scene);
        bool removeScene(std::shared_ptr<Scene> scene);
        bool removeScene(size_t index);

        size_t getScenesCount() const;

        void setActiveScene(const Scene& scene);
        void setActiveScene(size_t index);

        Scene* getActiveScene();
        const Scene* getActiveScene() const;

        void updateActiveScene();

        Scene& operator[](size_t index);
        const Scene& operator[](size_t index) const;

    };

    class SceneManagement
    {
        static SceneManager s_SceneManager;
    public:
    
            static void addScene(std::shared_ptr<Scene> scene);
            static bool removeScene(std::shared_ptr<Scene> scene);
            static bool removeScene(size_t index);
    
            static size_t getScenesCount();
    
            static void setActiveScene(const Scene& scene);
            static void setActiveScene(size_t index);
    
            static Scene* getActiveScene();
    
            static void updateActiveScene();
    
            static Scene& getScene(size_t index);
    };
}

#endif
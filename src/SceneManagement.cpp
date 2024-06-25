#ifdef _SCENE_MANAGEMENT_HPP
#include <smash.h>

namespace smash
{
    SceneManager SceneManagement::m_SceneManager;

    SceneManager::SceneManager()
        : m_ActiveScene(nullptr)
    {}

    void SceneManager::addScene(std::shared_ptr<Scene> scene)
    {
        m_Scenes.push_back(scene);
    }

    bool SceneManager::removeScene(std::shared_ptr<Scene> scene)
    {
        for (auto it = m_Scenes.begin(); it != m_Scenes.end(); ++it)
        {
            if (*it == scene)
            {
                m_Scenes.erase(it);
                return true;
            }
        }
        return false;
    }

    bool SceneManager::removeScene(size_t index)
    {
        if (index < m_Scenes.size())
        {
            m_Scenes.erase(m_Scenes.begin() + index);
            return true;
        }
        return false;
    }

    size_t SceneManager::getScenesCount() const
    {
        return m_Scenes.size();
    }

    void SceneManager::setActiveScene(std::shared_ptr<Scene> scene)
    {
        for (const auto& s : m_Scenes)
        {
            if (s == scene)
            {
                m_ActiveScene = scene.get();
                break;
            }
        }
    }

    Scene* SceneManager::getActiveScene()
    {
        return m_ActiveScene;
    }

    const Scene* SceneManager::getActiveScene() const
    {
        return m_ActiveScene;
    }

    void SceneManager::updateActiveScene()
    {
        if (m_ActiveScene)
            m_ActiveScene->update();
    }

    Scene& SceneManager::operator[](size_t index)
    {
        return *m_Scenes[index];
    }

    const Scene& SceneManager::operator[](size_t index) const
    {
        return *m_Scenes[index];
    }

    void SceneManagement::addScene(std::shared_ptr<Scene> scene)
    {
        m_SceneManager.addScene(scene);
    }

    bool SceneManagement::removeScene(std::shared_ptr<Scene> scene)
    {
        return m_SceneManager.removeScene(scene);
    }

    bool SceneManagement::removeScene(size_t index)
    {
        return m_SceneManager.removeScene(index);
    }

    size_t SceneManagement::getScenesCount()
    {
        return m_SceneManager.getScenesCount();
    }

    void SceneManagement::setActiveScene(std::shared_ptr<Scene> scene)
    {
        m_SceneManager.setActiveScene(scene);
    }

    Scene* SceneManagement::getActiveScene()
    {
        return m_SceneManager.getActiveScene();
    }

    void SceneManagement::updateActiveScene()
    {
        m_SceneManager.updateActiveScene();
    }

    Scene& SceneManagement::getScene(size_t index)
    {
        return m_SceneManager[index];
    }
}
#endif
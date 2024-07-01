
#include <smash.h>

namespace smash
{
    SceneManager SceneManagement::s_SceneManager;

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

    void SceneManager::setActiveScene(const Scene& scene)
    {
        for (auto& s : m_Scenes)
        {
            if (s.get() == &scene)
            {
                m_ActiveScene = s.get();
                break;
            }
        }
    }

    void SceneManager::setActiveScene(size_t index)
    {
        if (index < m_Scenes.size())
        {
            m_ActiveScene = m_Scenes[index].get();
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
        s_SceneManager.addScene(scene);
    }

    bool SceneManagement::removeScene(std::shared_ptr<Scene> scene)
    {
        return s_SceneManager.removeScene(scene);
    }

    bool SceneManagement::removeScene(size_t index)
    {
        return s_SceneManager.removeScene(index);
    }

    size_t SceneManagement::getScenesCount()
    {
        return s_SceneManager.getScenesCount();
    }

    void SceneManagement::setActiveScene(const Scene& scene)
    {
        s_SceneManager.setActiveScene(scene);
    }

    void SceneManagement::setActiveScene(size_t index)
    {
        s_SceneManager.setActiveScene(index);
    }

    Scene* SceneManagement::getActiveScene()
    {
        return s_SceneManager.getActiveScene();
    }

    void SceneManagement::updateActiveScene()
    {
        s_SceneManager.updateActiveScene();
    }

    Scene& SceneManagement::getScene(size_t index)
    {
        return s_SceneManager[index];
    }
}

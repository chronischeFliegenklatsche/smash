#ifdef _WIN32
#include <smash.h>

namespace smash
{
    GLInputAPI::GLInputAPI()
    {
        
    }

    GLInputAPI::~GLInputAPI()
    {
    }

    bool GLInputAPI::getKeyState(int key) const
    {
        return glfwGetKey(glfwGetCurrentContext(), key) == GLFW_PRESS;
    }

    void GLInputAPI::updateInputs(InputSystem& inputSystem) const
    {

        // Process mouse input
        double xPos, yPos;
        glfwGetCursorPos(glfwGetCurrentContext(), &xPos, &yPos);
        setAxis(inputSystem, "MouseX", (float)xPos);
        setAxis(inputSystem, "MouseY", (float)yPos);

        // Loop through all key codes and get their states
        for (int key = GLFW_KEY_SPACE; key <= GLFW_KEY_LAST; ++key)
        {
            setKeyState(inputSystem, (KeyCodes)key, getKeyState(key));
        }

        // Process axes
        setAxis(inputSystem, "Horizontal", getKeyState(GLFW_KEY_D) - getKeyState(GLFW_KEY_A));
        setAxis(inputSystem, "Vertical", getKeyState(GLFW_KEY_W) - getKeyState(GLFW_KEY_S));
    }

    void GLInputAPI::finishFrame() const
    {
        glfwPollEvents();
    }
}
#endif
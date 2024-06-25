#ifdef _GL_BASE_API_HPP
#include <smash.h>

namespace smash
{
    int GLBaseAPI::m_GLConsumersCount = 0;

    GLBaseAPI::GLBaseAPI()
    {
        GLFW_RegisterConsumer();
    }

    GLBaseAPI::~GLBaseAPI()
    {
        GLFW_UnregisterConsumer();
    }

    
    void window_close_callback(GLFWwindow* window)
    {
        Application::queueApplicationExit();
    }

    void framebuffer_size_callback(GLFWwindow* window, int width, int height)
    {
        // Make sure the window size is not minimized
        if (width > 0 && height > 0)
        {
            // Redraw the canvas
            glClear(GL_COLOR_BUFFER_BIT);

            // Set the OpenGL viewport to the new window size
            glViewport(0, 0, width, height);
        }
    }

    bool initGLFW()
    {

        // Initialize GLFW
        if (!glfwInit())
        {
            Diagnostics::print("Failed to initialize GLFW");
            return false;
        }

        // Create window
        GLFWwindow* window = glfwCreateWindow(800, 600, "GLBaseAPI", nullptr, nullptr);
        if (!window)
        {
            Diagnostics::print("Failed to create GLFW window");
            glfwTerminate();
            return false;
        }

        // Make current context
        glfwMakeContextCurrent(window);

        // Set the window close callback
        glfwSetWindowCloseCallback(window, window_close_callback);
        
        // Set the window resize callback
        glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

        Diagnostics::print("GLFW initialized");
        return true;
    }


    void GLBaseAPI::GLFW_RegisterConsumer()
    {
        if (m_GLConsumersCount == 0)
        {
            initGLFW();
        }

        m_GLConsumersCount++;
    }

    void GLBaseAPI::GLFW_UnregisterConsumer()
    {
        if (m_GLConsumersCount == 0)
        {
            Diagnostics::print("Error: GLFW reference count is already 0");
            return;
        }

        m_GLConsumersCount--;

        if (m_GLConsumersCount == 0)
        {
            glfwTerminate();
            Diagnostics::print("GLFW terminated");
        }
    }



}
#endif
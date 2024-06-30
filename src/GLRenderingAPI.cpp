#include "GLRenderingAPI.hpp"
#include <vector>
#include <cstring>
#include "Diagnostics.hpp"

namespace smash
{

GLRenderingAPI::GLRenderingAPI() : RenderingAPI(), GLBaseAPI()
{
    Diagnostics::print("GLRenderingAPI constructor called");

    // Initialize OpenGL context and create shaders
    if (!glfwGetCurrentContext())
    {
        Diagnostics::print("Error: No OpenGL context available");
        return;
    }

    Diagnostics::print("OpenGL context is available");

    // Create and compile shaders
    const char* vertexShaderSource = R"(
        #version 330 core
        layout (location = 0) in vec2 aPos;
        layout (location = 1) in vec3 aColor;
        out vec3 ourColor;
        void main()
        {
            gl_Position = vec4(aPos.x, aPos.y, 0.0, 1.0);
            ourColor = aColor;
        }
    )";

    const char* fragmentShaderSource = R"(
        #version 330 core
        in vec3 ourColor;
        out vec4 FragColor;
        void main()
        {
            FragColor = vec4(ourColor, 1.0);
        }
    )";

    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    // Check vertex shader compilation
    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        Diagnostics::print("Vertex shader compilation failed: " + std::string(infoLog));
    }

    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    // Check fragment shader compilation
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        Diagnostics::print("Fragment shader compilation failed: " + std::string(infoLog));
    }

    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    // Check shader program linking
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        Diagnostics::print("Shader program linking failed: " + std::string(infoLog));
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    // Create VAO and VBO
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);

    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(2 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    Diagnostics::print("GLRenderingAPI initialization completed");
}

GLRenderingAPI::~GLRenderingAPI()
{
    Diagnostics::print("GLRenderingAPI destructor called");
    glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(1, &vbo);
    glDeleteProgram(shaderProgram);
}

// ... (other methods remain the same)

void GLRenderingAPI::swapFrameBuffers() const
{
    GLFWwindow* window = glfwGetCurrentContext();
    if (window)
    {
        glfwSwapBuffers(window);
        glfwPollEvents();  // Process events to keep the window responsive
    }
    else
    {
        Diagnostics::print("Error: No GLFW window available for swapFrameBuffers");
    }
}

}
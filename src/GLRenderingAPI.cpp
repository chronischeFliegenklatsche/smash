#ifdef _GL_RENDERING_API_HPP
#include <smash.h>

// Vertex shader source code
const char* vertexShaderSource = R"(
#version 460 core
layout (location = 0) in vec2 aPos;
void main()
{
    gl_Position = vec4(aPos, 0.0, 1.0);
}
)";

// Fragment shader source code
const char* fragmentShaderSource = R"(
#version 460 core
out vec4 FragColor;
uniform vec3 uColor;
void main()
{
    FragColor = vec4(uColor, 1.0);
}
)";

namespace smash
{
    GLRenderingAPI::GLRenderingAPI()
    {
        // Initialize GLAD
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            Diagnostics::print("Failed to initialize GLAD");
            return;
        }

        // Create a vertex array object
        glGenVertexArrays(1, &vao);
        glBindVertexArray(vao);

        // Create a vertex buffer object
        glGenBuffers(1, &vbo);
        glBindBuffer(GL_ARRAY_BUFFER, vbo);

        // Define the vertex data
        float vertices[] = {
            // Position  Color
            -1.0f, -1.0f, 1.0f, 0.0f, 0.0f, // Bottom-left
             1.0f, -1.0f, 0.0f, 1.0f, 0.0f, // Bottom-right
             1.0f,  1.0f, 0.0f, 0.0f, 1.0f, // Top-right
            -1.0f,  1.0f, 1.0f, 1.0f, 1.0f  // Top-left
        };

        // Upload the vertex data to the buffer
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        // Define the vertex attribute pointers
        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(2 * sizeof(float)));
        glEnableVertexAttribArray(1);

        // Create a shader program
        unsigned int vertexShader, fragmentShader;
        vertexShader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
        glCompileShader(vertexShader);

        fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
        glCompileShader(fragmentShader);

        shaderProgram = glCreateProgram();
        glAttachShader(shaderProgram, vertexShader);
        glAttachShader(shaderProgram, fragmentShader);
        glLinkProgram(shaderProgram);

        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
    }

    GLRenderingAPI::~GLRenderingAPI()
    {
        glDeleteVertexArrays(1, &vao);
        glDeleteBuffers(1, &vbo);
        glDeleteProgram(shaderProgram);
    }

    void GLRenderingAPI::drawPixel(int x, int y, uint16_t color) const
    { 
        // Convert the 16-bit color to RGB components
        float r = ((color >> 11) & 0x1F) / 31.0f;
        float g = ((color >> 5) & 0x3F) / 63.0f;
        float b = (color & 0x1F) / 31.0f;

        // Convert pixel coordinates to normalized device coordinates (NDC)
        int width, height;
        glfwGetFramebufferSize(glfwGetCurrentContext(), &width, &height);
        float ndcX = (2.0f * x) / width - 1.0f;
        float ndcY = 1.0f - (2.0f * y) / height;

        // Set up the vertex data for the point
        float vertices[] = { ndcX, ndcY };

        // Bind the VAO and VBO
        glBindVertexArray(vao);
        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        // Use the shader program
        glUseProgram(shaderProgram);

        // Set the color uniform
        int colorLocation = glGetUniformLocation(shaderProgram, "uColor");
        glUniform3f(colorLocation, r, g, b);

        // Draw the point
        glDrawArrays(GL_POINTS, 0, 1);

        // Unbind the VAO and VBO
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);
    }

    void GLRenderingAPI::swapFrameBuffers() const
    {
        glfwSwapBuffers(glfwGetCurrentContext());
        glClear(GL_COLOR_BUFFER_BIT);
    }
}
#endif
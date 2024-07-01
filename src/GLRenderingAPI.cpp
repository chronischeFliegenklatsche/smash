#include <smash.h>
#include <vector>
#include <cstring>

namespace smash
{

    GLRenderingAPI::GLRenderingAPI() : RenderingAPI(), GLBaseAPI()
    {

        // Initialize OpenGL context and create shaders
        if (!glfwGetCurrentContext())
        {
            return;
        }

        // Load OpenGL functions
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            Diagnostics::print("Failed to initialize GLAD");
            return;
        }

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
        }

        GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
        glCompileShader(fragmentShader);

        // Check fragment shader compilation
        glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        }

        shaderProgram = glCreateProgram();
        glAttachShader(shaderProgram, vertexShader);
        glAttachShader(shaderProgram, fragmentShader);
        glLinkProgram(shaderProgram);

        // Check shader program linking
        glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
        if (!success) {
            glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
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

    }

    GLRenderingAPI::~GLRenderingAPI()
    {
        glDeleteVertexArrays(1, &vao);
        glDeleteBuffers(1, &vbo);
        glDeleteProgram(shaderProgram);
    }

    void GLRenderingAPI::drawPixel(int x, int y, uint16_t color) const
    {
        float xPos = (float)x / (float)getCanvasWidth() * 2.0f - 1.0f;
        float yPos = 1.0f - (float)y / (float)getCanvasHeight() * 2.0f;

        float r = ((color >> 11) & 0x1F) / 31.0f;
        float g = ((color >> 5) & 0x3F) / 63.0f;
        float b = (color & 0x1F) / 31.0f;

        float vertices[] = {
            xPos, yPos, r, g, b
        };

        glUseProgram(shaderProgram);
        glBindVertexArray(vao);
        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
        glDrawArrays(GL_POINTS, 0, 1);
    }

    void GLRenderingAPI::drawRect(int x, int y, int w, int h, uint16_t color) const
    {
        float x1 = (float)x / (float)getCanvasWidth() * 2.0f - 1.0f;
        float y1 = 1.0f - (float)y / (float)getCanvasHeight() * 2.0f;
        float x2 = (float)(x + w) / (float)getCanvasWidth() * 2.0f - 1.0f;
        float y2 = 1.0f - (float)(y + h) / (float)getCanvasHeight() * 2.0f;

        float r = ((color >> 11) & 0x1F) / 31.0f;
        float g = ((color >> 5) & 0x3F) / 63.0f;
        float b = (color & 0x1F) / 31.0f;

        float vertices[] = {
            x1, y1, r, g, b,
            x2, y1, r, g, b,
            x2, y2, r, g, b,
            x1, y2, r, g, b
        };

        glUseProgram(shaderProgram);
        glBindVertexArray(vao);
        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
        glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
    }

    void GLRenderingAPI::drawCanvas(const Canvas& _canvas) const
    {
        for (size_t y = 0; y < _canvas.getHeight(); ++y)
        {
            for (size_t x = 0; x < _canvas.getWidth(); ++x)
            {
                drawPixel(x, y, _canvas.getPixel(x, y).getRGB16());
            }
        }
    }

    size_t GLRenderingAPI::getCanvasWidth() const
    {
        int width;
        glfwGetFramebufferSize(glfwGetCurrentContext(), &width, nullptr);
        return static_cast<size_t>(width);
    }

    size_t GLRenderingAPI::getCanvasHeight() const
    {
        int height;
        glfwGetFramebufferSize(glfwGetCurrentContext(), nullptr, &height);
        return static_cast<size_t>(height);
    }

    void GLRenderingAPI::swapFrameBuffers() const
    {
        GLFWwindow* window = glfwGetCurrentContext();
        if (window)
        {
            glfwSwapBuffers(window);
            glfwPollEvents();  // Process events to keep the window responsive
        }
    }

    

} 
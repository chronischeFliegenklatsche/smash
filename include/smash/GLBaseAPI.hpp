#ifndef _GLFW_API_HPP
#define _GLFW_API_HPP

namespace smash
{
    class GLBaseAPI;
    class GLBaseAPI
    {
        static int m_GLConsumersCount;
        static void GLFW_RegisterConsumer();
        static void GLFW_UnregisterConsumer();
    public:
        GLBaseAPI();
        ~GLBaseAPI();
    };
}

#endif
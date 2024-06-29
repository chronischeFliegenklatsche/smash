#ifndef _GLFW_INPUT_API_HPP
#define _GLFW_INPUT_API_HPP

#include "InputAPI.hpp"
#include "GLBaseAPI.hpp"
#include <GLFW/glfw3.h>

namespace smash
{
    class GLInputAPI;
    class GLInputAPI : public InputAPI, public GLBaseAPI
    {
        bool getKeyState(int key) const;
    public:
    
        GLInputAPI();
        ~GLInputAPI() override;

        void updateInputs(InputSystem& inputSystem) const override;
        void finishFrame() const override;
    };
}

#endif
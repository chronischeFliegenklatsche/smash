#ifndef _INPUT_DETECTION_HPP
#define _INPUT_DETECTION_HPP

#include <memory>

#include "InputAPI.hpp"
#include "InputSystem.hpp"

namespace smash
{
    class InputDetector;
    class InputDetection;

    class InputDetector
    {
        std::unique_ptr<InputAPI> m_InputAPI;
    public:

        InputDetector();
        ~InputDetector();

        void bindInputAPI(std::unique_ptr<InputAPI> inputAPI);

        void updateInputs(InputSystem& inputSystem) const;

    };

    class InputDetection
    {
        static InputDetector m_InputDetector;
    public:

        static void bindInputAPI(std::unique_ptr<InputAPI> inputAPI);

        static void updateInputs();

        static void shutdown();
    };

}

#endif
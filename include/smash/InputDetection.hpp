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
        std::unique_ptr<const InputAPI> m_InputAPI;
    public:

        InputDetector();
        virtual ~InputDetector();

        void bindInputAPI(std::unique_ptr<const InputAPI> inputAPI);

        void updateInputs(InputSystem& inputSystem) const;

    };

    class InputDetection
    {
        static InputDetector m_InputDetector;
    public:

        static void bindInputAPI(std::unique_ptr<const InputAPI> inputAPI);

        static void updateInputs();
    };

}

#endif
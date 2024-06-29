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
        std::shared_ptr<const InputAPI> m_InputAPI;
    public:

        InputDetector();
        virtual ~InputDetector();

        void setInputAPI(std::shared_ptr<const InputAPI> inputAPI);
        std::shared_ptr<const InputAPI> getInputAPI() const;

        void updateInputs(InputSystem& inputSystem) const;

    };

    class InputDetection
    {
        static InputDetector m_InputDetector;
    public:

        static void setInputAPI(std::shared_ptr<const InputAPI> inputAPI);
        std::shared_ptr<const InputAPI> getInputAPI();

        static void updateInputs();
    };

}

#endif
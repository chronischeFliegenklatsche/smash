#ifndef _TEST_COMPONENT_HPP
#define _TEST_COMPONENT_HPP
#include "Component.hpp"

namespace smash
{
    class TestComponent;
    class TestComponent : public Component
    {
    public:

        TestComponent();
        ~TestComponent();

        virtual void update() override;
        std::unique_ptr<Component> clone() const override;
        std::string getTypeName() const override;
        
    };
}
#endif
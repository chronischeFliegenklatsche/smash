
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
        Component* clone() const override;
        std::string getTypeName() const override;
    };
}

#include <smash.h>

#ifdef _WIN32
#include <iostream>
#endif

#ifdef ESP32
#include <Arduino.h>
#endif

namespace smash
{
    TestComponent::TestComponent() : Component() { Diagnostics::print("Constructed TestComponent instance."); }
    TestComponent::~TestComponent() { Diagnostics::print("Destructed TestComponent instance."); }
    void TestComponent::update()
    {
        Diagnostics::print("Updated TestComponent instance.");
    }

    std::unique_ptr<Component> TestComponent::clone() const
    {
        return std::make_unique<TestComponent>();
    }

    std::string TestComponent::getTypeName() const
    {
        return "TestComponent";
    }
}

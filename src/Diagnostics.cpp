
#include <smash.h>

#ifdef _WIN32
#include <iostream>
#endif

#ifdef ESP32
#include <Arduino.h>
#endif

namespace smash
{
    Diagnoser::Diagnoser()
    {
#ifdef ESP32
        Serial.begin(115200);   
#endif
    }

    void Diagnoser::print(std::string text)
    {
#ifdef _WIN32
        std::cout << text << std::endl;
#endif
#ifdef ESP32
        Serial.println(text.c_str());
#endif
    }

    void Diagnoser::memoryTest(int componentsCount)
    {
        print("-------------------------------------");
        print("Initializing performance test over " + std::to_string(componentsCount) + " components.");
        ComponentsContainer compContainer;
        Component **components = new Component*[componentsCount];
        int i = 0;
        bool loopValid = false;

        print("-------------------------------------");
        print("Construction");
        print("-------------------------------------");
        for (int i = 0; i < componentsCount; ++i)
        {
            components[i] = new TestComponent();
            compContainer.addComponent(*components[i]);
            print(std::to_string(componentsCount - i - 1) + " still have to pass.");
            loopValid = (i == componentsCount - 1);
        }

        if (!loopValid)
        {
            goto fail;
        }

        print("-------------------------------------");
        print("Iteration");
        print("-------------------------------------");
        for (Component& component : compContainer)
        {
            component.update();
            print((std::to_string(componentsCount - i - 1) + " still have to pass."));
            loopValid = (i == componentsCount - 1);
            i++;
        }

        if (!loopValid)
        {
            goto fail;
        }

        print("-------------------------------------");
        print("Destruction");
        print("-------------------------------------");
        for (int i = 0; i < componentsCount; ++i)
        {
            delete components[i];
            print((std::to_string(componentsCount - i - 1) + " still have to pass."));
            loopValid = (i == componentsCount - 1);  
        }

        if (!loopValid)
        {
            goto fail;
        }

        delete[] components;
        print("-------------------------------------");
        print("Performance test passed succesfully!!");
        print("-------------------------------------");
        return;
fail:
        print("-------------------------------------");
        print("Performance test failed!!");
        print("-------------------------------------");
    }

    Diagnoser Diagnostics::_diagnoser;

    void Diagnostics::print(std::string text)
    {
        _diagnoser.print(text);
    }

    void Diagnostics::memoryTest(int componentsCount)
    {
        _diagnoser.memoryTest(componentsCount);
    }
}

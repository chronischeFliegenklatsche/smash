#ifndef _DIAGNOSTICS_HPP
#define _DIAGNOSTICS_HPP

#include <string>

namespace smash
{
    class Diagnoser;
    class Diagnostics;

    class Diagnoser
    {
    public:
        Diagnoser();
        void print(std::string text);
        void memoryTest(int componentsCount);
    };

    class Diagnostics
    {
        friend class Diagnoser;
        static Diagnoser _diagnoser;
    public:
        static void print(std::string text);
        static void memoryTest(int componentsCount);
#ifdef ESP32
    private:
        static bool _SERIAL_INITIALIZED;
    public:
        static void initializeSerialConnection();
        static void printRAMInfo();
#endif
    };
}

#endif
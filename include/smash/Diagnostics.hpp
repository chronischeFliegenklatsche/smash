#ifndef _DIAGNOSTICS_HPP
#define _DIAGNOSTICS_HPP

#include "String.hpp"

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
        static Diagnoser _diagnoser;
    public:
        static void print(std::string text);
        static void memoryTest(int componentsCount);
    };
}

#endif
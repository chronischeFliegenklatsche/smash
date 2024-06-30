#ifndef _RANDOM_HPP
#define _RANDOM_HPP

namespace smash
{
    class Randomizer;
    class Random;

    class Randomizer
    {
    public:

        Randomizer();
        ~Randomizer();

        int randomInt(int min, int max);
    };

    class Random
    {
        static Randomizer s_Randomizer;
    public:
        static int randomInt(int min, int max) { return s_Randomizer.randomInt(min, max); }
    };
}

#endif
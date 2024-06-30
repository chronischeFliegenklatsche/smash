#include <smash.h>
#ifdef ESP32
#include <esp_random.h>
#endif

namespace smash
{
    // Initialize the static member of Random
    Randomizer Random::s_Randomizer;

    Randomizer::Randomizer()
    {
        // No need to seed for ESP32, as we'll use esp_random()
    }

    Randomizer::~Randomizer()
    {
        // Destructor (empty in this case)
    }

    int Randomizer::randomInt(int min, int max)
    {
        if (min > max)
        {
            // Swap min and max if they're in the wrong order
            int temp = min;
            min = max;
            max = temp;
        }

        // Use ESP32's hardware random number generator
        uint32_t randomValue;
#ifdef ESP32
        randomValue = esp_random();
#endif
        // Scale the random value to the desired range
        return min + (randomValue % (max - min + 1));
    }
}
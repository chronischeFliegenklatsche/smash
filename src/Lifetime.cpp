#include <smash.h>


namespace smash
{
    void _SMASH_ENGINE_LIFETIME(Runtime& runtime)
    {
        while (!runtime.getRuntimeExitQueued())
        {
            runtime.pipe();
        }
    }
}
#include <smash.h>


namespace smash
{
    void _SMASH_ENGINE_LOOP(Runtime& runtime)
    {
        while (!runtime.getRuntimeExitQueued())
        {
            runtime.pipe();
        }
    }
}
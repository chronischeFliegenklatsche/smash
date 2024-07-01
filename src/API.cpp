#include <smash.h>

namespace smash
{
    void API::shutdown()
    {}

    API::~API()
    {
        shutdown();
    }
}
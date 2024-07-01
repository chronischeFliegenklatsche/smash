#include <smash.h>

namespace smash
{
    void API::shutdown()
    {}

    API::~API()
    {
        Diagnostics::print("MAKE API SHUTDOWN");
        shutdown();
    }
}
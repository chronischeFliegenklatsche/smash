#ifndef _API_HPP
#define _API_HPP

namespace smash
{
    class API
    {
    public:

        API() = default;
        virtual ~API();

        virtual void shutdown();
    };
}

#endif
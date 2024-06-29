#ifndef _TYPE_NAME_PROVIDER_HPP
#define _TYPE_NAME_PROVIDER_HPP

#include <string>

namespace smash
{
    class TypeNameProvider;

    class TypeNameProvider
    {
    public:
        virtual std::string getTypeName() const = 0;  
    };
}

#endif
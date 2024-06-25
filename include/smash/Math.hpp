#ifndef _MATH_HPP
#define _MATH_HPP

#ifdef _WIN32
#include <cmath>
#endif

#ifdef ARDUINO
#include <math.h>

namespace std
{
    template <typename T>
    T abs(T value)
    {
        return value < 0 ? -value : value;
    }

    template <typename T>
    T sqrt(T value)
    {
        return ::sqrt(value);
    }

    template <typename T>
    T sin(T value)
    {
        return ::sin(value);
    }

    template <typename T>
    T cos(T value)
    {
        return ::cos(value);
    }

    template <typename T>
    T tan(T value)
    {
        return ::tan(value);
    }

    template <typename T>
    T asin(T value)
    {
        return ::asin(value);
    }

    template <typename T>
    T acos(T value)
    {
        return ::acos(value);
    }

    template <typename T>
    T atan(T value)
    {
        return ::atan(value);
    }

    template <typename T>
    T atan2(T y, T x)
    {
        return ::atan2(y, x);
    }

    template <typename T>
    T exp(T value)
    {
        return ::exp(value);
    }

    template <typename T>
    T log(T value)
    {
        return ::log(value);
    }

    template <typename T>
    T log10(T value)
    {
        return ::log10(value);
    }

    template <typename T>
    T pow(T base, T exponent)
    {
        return ::pow(base, exponent);
    }

    template <typename T>
    T ceil(T value)
    {
        return ::ceil(value);
    }

    template <typename T>
    T floor(T value)
    {
        return ::floor(value);
    }

    template <typename T>
    T fmod(T numer, T denom)
    {
        return ::fmod(numer, denom);
    }

    template <typename T>
    T round(T value)
    {
        return ::round(value);
    }

    template <typename T>
    T trunc(T value)
    {
        return ::trunc(value);
    }

    template <typename T>
    T rint(T value)
    {
        return ::rint(value);
    }

    template <typename T>
    T remainder(T numer, T denom)
    {
        return ::remainder(numer, denom);
    }

    template <typename T>
    T copysign(T x, T y)
    {
        return ::copysign(x, y);
    }

}

#endif

#endif
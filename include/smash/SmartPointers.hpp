#ifndef _SMART_POINTERS_HPP
#define _SMART_POINTERS_HPP

#ifdef _WIN32
#include <memory>
#endif

#ifdef ESP32
#include <memory>
#pragma message("Using esp ptrs")
#elif defined(ARDUINO)
#include <ArxSmartPtr.h>
#endif

#endif
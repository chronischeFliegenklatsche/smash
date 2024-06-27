#ifndef _CONTAINERS_HPP
#define _CONTAINERS_HPP

#ifdef _WIN32
#include <vector>
#include <array>
#include <map>
#include <deque>
#include <utility>
#endif

#ifdef ESP32
#include <vector>
#include <array>
#include <map>
#include <deque>
#include <utility>
#elif defined(ARDUINO)
#include <ArxContainer.h>
#endif

#endif
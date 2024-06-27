#ifndef _STRING_HPP
#define _STRING_HPP

#ifdef _WIN32
#include <string>
#endif

#ifdef ESP32
#include <string>
#elif defined(ARDUINO)
#include <Arduino.h>
#include <ArxStringUtils.h>
#endif

#endif
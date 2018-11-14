/**
 * Author: Drake Eidukas
 * Useful little library for having configurable log levels.
 */

#ifndef LOG_H // include guard
#define LOG_H

#include <stdio.h>

// https://en.wikipedia.org/wiki/ANSI_escape_code#Colors
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"
#define ANSI_COLOR_ORANGE  "\x1b[38;2;255;165;0m"


#define __LOG_COLOR(COLOR, ...) fflush(stderr); fprintf(stderr, "%s[%s:%d] %s%s(): %s", ANSI_COLOR_MAGENTA, __FILE__, __LINE__, ANSI_COLOR_GREEN, __func__, COLOR); fprintf(stderr, __VA_ARGS__); fprintf(stderr, "%s\n", ANSI_COLOR_RESET);

#ifndef LOG_LEVEL
#define LOG_LEVEL 5
#endif

#undef LOG
#define LOG(...)

#undef LOG_INFO
#define LOG_INFO(...)

#undef LOG_DEBUG
#define LOG_DEBUG(...)

#undef LOG_WARN
#define LOG_WARN(...)

#undef LOG_ERROR
#define LOG_ERROR(...)

#ifndef LOG_COLOR_ERROR
#define LOG_COLOR_ERROR ANSI_COLOR_RED
#endif

#ifndef LOG_COLOR_WARN
#define LOG_COLOR_WARN ANSI_COLOR_ORANGE
#endif

#ifndef LOG_COLOR_DEBUG
#define LOG_COLOR_DEBUG ANSI_COLOR_YELLOW
#endif 

#ifndef LOG_COLOR_INFO
#define LOG_COLOR_INFO ANSI_COLOR_CYAN
#endif 

#ifndef LOG_COLOR
#define LOG_COLOR ANSI_COLOR_RESET
#endif

// If LOG_LEVEL is 1 or greater, enable error logging
#if LOG_LEVEL > __COUNTER__
#undef LOG_ERROR
#define LOG_ERROR(...) __LOG_COLOR(LOG_ERROR_COLOR, __VA_ARGS__)
#endif

// If log level is 2 or greater, enable warn logging
#if LOG_LEVEL > __COUNTER__
#undef LOG_WARN
#define LOG_WARN(...) __LOG_COLOR(LOG_WARN_COLOR, __VA_ARGS__)
#endif

// If log level is 3 or greater, enable debug logging
#if LOG_LEVEL > __COUNTER__
#undef LOG_DEBUG
#define LOG_DEBUG(...) __LOG_COLOR(LOG_DEBUG_COLOR, __VA_ARGS__)
#endif

// If log level is 4 or greater, enable info logging
#if LOG_LEVEL > __COUNTER__
#undef LOG_INFO
#define LOG_INFO(...) __LOG_COLOR(LOG_INFO_COLOR, __VA_ARGS__)
#endif

// If log level is 5 or greater, enable all logging
#if LOG_LEVEL > __COUNTER__
#undef LOG
#define LOG(...) __LOG_COLOR(LOG_COLOR, __VA_ARGS__)
#endif

#endif // include guard

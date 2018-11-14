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
#define LOG_COLOR_DEBUG ANSI_COLOR_BLUE
#endif

#ifndef LOG_COLOR_INFO
#define LOG_COLOR_INFO ANSI_COLOR_CYAN
#endif

#ifndef LOG_COLOR
#define LOG_COLOR ANSI_COLOR_RESET
#endif

#ifndef LINE_NUMBER_COLOR
#define LINE_NUMBER_COLOR ANSI_COLOR_MAGENTA
#endif

#ifndef FUNCTION_NAME_COLOR
#define FUNCTION_NAME_COLOR ANSI_COLOR_GREEN
#endif

#ifndef FLUSH_BEFORE
#define FLUSH_BEFORE 1
#endif

#ifndef FLUSH_AFTER
#define FLUSH_AFTER 1
#endif

#ifndef PRINT_LINE_NUMBER
#define PRINT_LINE_NUMBER 1
#endif

#ifndef PRINT_FUNCTION_NAME
#define PRINT_FUNCTION_NAME 1
#endif

#define __LOG_COLOR(COLOR, FORMAT, ...) \
                                if (FLUSH_BEFORE) { fflush(stderr); } \
                                if (PRINT_LINE_NUMBER) { fprintf(stderr, "%s[%s:%d]%s ", LINE_NUMBER_COLOR, __FILE__, __LINE__, ANSI_COLOR_RESET); } \
                                if (PRINT_FUNCTION_NAME) { fprintf(stderr, "%s%s(): %s", FUNCTION_NAME_COLOR, __func__, ANSI_COLOR_RESET); } \
                                fprintf(stderr, "%s", COLOR); \
                                fprintf(stderr, FORMAT, ##__VA_ARGS__); \
                                fprintf(stderr, "%s\n", ANSI_COLOR_RESET); \
                                if (FLUSH_AFTER) { fflush(stderr); }

// If LOG_LEVEL is 1 or greater, enable error logging
#if LOG_LEVEL > __COUNTER__
#undef LOG_ERROR
#define LOG_ERROR(FORMAT, ...) __LOG_COLOR(LOG_COLOR_ERROR, FORMAT, ##__VA_ARGS__)
#endif

// If log level is 2 or greater, enable warn logging
#if LOG_LEVEL > __COUNTER__
#undef LOG_WARN
#define LOG_WARN(FORMAT, ...) __LOG_COLOR(LOG_COLOR_WARN, FORMAT, ##__VA_ARGS__)
#endif

// If log level is 3 or greater, enable debug logging
#if LOG_LEVEL > __COUNTER__
#undef LOG_DEBUG
#define LOG_DEBUG(FORMAT, ...) __LOG_COLOR(LOG_COLOR_DEBUG, FORMAT, ##__VA_ARGS__)
#endif

// If log level is 4 or greater, enable info logging
#if LOG_LEVEL > __COUNTER__
#undef LOG_INFO
#define LOG_INFO(FORMAT, ...) __LOG_COLOR(LOG_COLOR_INFO, FORMAT, ##__VA_ARGS__)
#endif

// If log level is 5 or greater, enable all logging
#if LOG_LEVEL > __COUNTER__
#undef LOG
#define LOG(FORMAT, ...) __LOG_COLOR(LOG_COLOR, FORMAT, ##__VA_ARGS__)
#endif

#endif // include guard

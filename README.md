# clogger
Simple C header file which permits easy logging in C using macros.
Usage: 
There are 5 provided log levels in order of decreasing verbosity:
- LOG 
  - Runs if LOG_LEVEL >= 5
- LOG_INFO
  - Runs if LOG_LEVEL >= 4
- LOG_DEBUG
  - Runs if LOG_LEVEL >= 3
- LOG_WARN
  - Runs if LOG_LEVEL >= 2
- LOG_ERROR
  - Runs if LOG_LEVEL >= 1

By default, the LOG_LEVEL is 5, thus, it will print all of the different log levels to stderr.
You can change this by defining LOG_LEVEL to be something lower.
You can also change the colors by defining macros to any valid ansi [escape code](https://en.wikipedia.org/wiki/ANSI_escape_code).

Example with full defaults: 
![Default Configuration](https://imgur.com/7ej7v1T)
![Default Configuration Results](https://imgur.com/OnzT2xW)
Example with some changed defaults:
![With Config Details](https://imgur.com/xlT7djV)
![With Config Details Results](https://imgur.com/SD6QyU1)

----
Full list of configuration settings (make sure to define these before including log.h):
- LOG_LEVEL
  - Number that changes the verbosity of logging as described above
- LOG_COLOR_ERROR
  - Define this to be an ansi color code to change the color of text in `LOG_ERROR`
- LOG_COLOR_WARN
  - Define this to be an ansi color code to change the color of text in `LOG_WARN`
- LOG_COLOR_DEBUG
  - Define this to be an ansi color code to change the color of text in `LOG_DEBUG`
- LOG_COLOR_INFO
  - Define this to be an ansi color code to change the color of text in `LOG_INFO`
- LOG_COLOR
  - Define this to be an ansi color code to change the color of text in `LOG`
- LINE_NUMBER_COLOR
  - Define this to be an ansi color code to change the color of the printed line numbers
- FUNCTION_NAME_COLOR
  - Define this to be an ansi color code to change the color of the printed function names
- FLUSH_BEFORE
  - Set this to `false` if you don't want to call `fflush(stderr)` before the log message
- FLUSH_AFTER
  - Set this to `false` if you don't want to call `fflush(stderr)` after the log message
- PRINT_LINE_NUMBER
  - Set this to `false` if you don't want to print the line numbers 
- PRINT_FUNCTION_NAME
  - Set this to `false` if you don't want to print the function name

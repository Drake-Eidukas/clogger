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
![Default Configuration](/Full_logging_config.png?raw=true)
![Default Configuration Results](Full_logging.png?raw=true)
Example with some changed defaults:
![With Config Details](Modified_logging_config.png?raw=true)
![With Config Details Results](Modified_logging.png?raw=true)

----
Full list of configuration settings:

/**
 * @file log.h
 * @brief 
 * @author BenYuLong 
 * @date 2020/09/29
 */

#ifndef _LOG_H
#define _LOG_H

#define COLOR(msg, code) "\033[0;1;" #code "m" msg "\033[0m"
#define RED(msg)    COLOR(msg, 31)
#define GREEN(msg)  COLOR(msg, 32)
#define YELLOW(msg) COLOR(msg, 33)
#define BLUE(msg)   COLOR(msg, 34)

#ifndef LOG_LEVEL
#define LOG_LEVEL 5
#endif

#define LOG_MODULE_NULL      "N"
#define LOG_MODULE_SECTION0  "SEC0"


#define LOG_T(prefix, module, level, ...) \
    if (level < LOG_LEVEL) {       \
        printf(prefix module " : " __VA_ARGS__); \
        printf("\n");  \
    }

#define FATAL(module, ...) LOG_T(RED("[fatal]"), module, 0, __VA_ARGS__)
#define ERROR(module, ...) LOG_T(RED("[error]"), module, 1, __VA_ARGS__)
#define WARN(module, ...)  LOG_T(YELLOW("[warn ]"), module, 2, __VA_ARGS__)
#define INFO(module, ...)  LOG_T("[info ]", module, 3, __VA_ARGS__)
#define DEBUG(module, ...) LOG_T("[debug]", module, 4, __VA_ARGS__)


#endif

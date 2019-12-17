//
//  Log.hpp
//  LW6
//
//  Created by Stanislav Martynov on 17.12.2019.
//  Copyright © 2019 Stanislav Martynov. All rights reserved.
//

#ifndef Log_hpp
#define Log_hpp

#include <stdio.h>
#include <stdio.h>
#include <cstdio>
#include <string>

class c_log
{
public:
    enum logger_level
    {
        lvl_trace,
        lvl_debug,
        lvl_info,
        lvl_warning,
        lvl_error,
        lvl_fatal
    };
    c_log();
    void print_info(logger_level level, const char *format, ...);
private:
    void output(logger_level level, std::string str);
};

c_log& log();

#define log_info(fmt, ...)                      log().print_info(c_log::lvl_info, fmt, __VA_ARGS__)
#define log_trace(fmt, ...)                     log().print_info(c_log::lvl_trace, fmt, __VA_ARGS__)
#define log_msg_lvl(lvl, fmt, ...)              log().print_info(lvl, fmt, __VA_ARGS__)
#endif /* Log_hpp */

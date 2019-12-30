//
//  log.hpp
//  LW6
//
//  Created by Stanislav Martynov on 17.12.2019.
//  Copyright © 2019 Stanislav Martynov. All rights reserved.
//


#pragma once
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
private:
    void output(logger_level level, std::string str);
};

c_log& log();



//
//  log.cpp
//  LW6
//
//  Created by Stanislav Martynov on 17.12.2019.
//  Copyright © 2019 Stanislav Martynov. All rights reserved.
//

#include "log.hpp"
#include <stdarg.h>
#include <ostream>
#include <fstream>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/utility/manipulators/add_value.hpp>
#include <boost/date_time/posix_time/posix_time_types.hpp>
#include "boost/log/trivial.hpp"
#include <boost/log/expressions.hpp>
#include "boost/log/utility/setup.hpp"
#include <boost/log/support/date_time.hpp>

static void init_log(const std::string path = "C:\\Temp\\", const int rotation_size = 10*1024*1024, const int max_size = 100*1024*1024)
{
    static const std::string COMMON_FMT("[%TimeStamp%][%Severity%]:  %Message%");

    boost::log::register_simple_formatter_factory< boost::log::trivial::severity_level, char >("Severity");


    boost::log::add_console_log(std::cout, boost::log::keywords::format = COMMON_FMT);

    boost::log::add_file_log (
        boost::log::keywords::file_name = path +  "log_%N.log",
        boost::log::keywords::open_mode = ( std::ios::out | std::ios::app),
        boost::log::keywords::rotation_size = rotation_size,
        boost::log::keywords::max_size = max_size,
        boost::log::keywords::time_based_rotation = boost::log::sinks::file::rotation_at_time_point(0, 0, 0),
        boost::log::keywords::format = COMMON_FMT,
        boost::log::keywords::auto_flush = true
    );

    boost::log::add_common_attributes();

#ifndef _DEBUG
    boost::log::core::get()->set_filter(
        boost::log::trivial::severity >= boost::log::trivial::info
    );
#endif

}

c_log::c_log()
{
    init_log();
}



void c_log::output(c_log::logger_level level, const std::string& str)
{
    switch (level)
    {
    case lvl_info:
        BOOST_LOG_TRIVIAL(info) << "An informational severity message";
        break;
    case lvl_debug:
        BOOST_LOG_TRIVIAL(debug) << "A debug severity message";
        break;
    case lvl_error:
        BOOST_LOG_TRIVIAL(error) << "An error severity message";
        break;
    case lvl_fatal:
        BOOST_LOG_TRIVIAL(fatal) << "A fatal severity message";
        break;
    case lvl_trace:
        BOOST_LOG_TRIVIAL(trace) << "A trace severity message";
        break;
    case lvl_warning:
        BOOST_LOG_TRIVIAL(warning) << "A warning severity message";
        break;
    default:
        throw std::invalid_argument("level");
    }
    
}

c_log &log()
{
    static c_log logger;
    return logger;
}

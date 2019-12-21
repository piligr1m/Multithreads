//
//  main.cpp
//  LW6
//
//  Created by Stanislav Martynov on 17.12.2019.
//  Copyright © 2019 Stanislav Martynov. All rights reserved.
//

#include <iostream>
#include <exception>
#include <thread>
#include <sstream>
#include <boost/lexical_cast.hpp>
#include "boost/log/trivial.hpp"
#include <vector>
#include <algorithm>
#include "Threads.hpp"
#include "Log.hpp"

void thr_func()
{
    std::stringstream ss;
    ss << std::this_thread::get_id();
    while(1)
    {
        c_task obj(ss.str());
    }
}

int main(int argc, char* argv[])
{
    try
    {
        unsigned int m = std::thread::hardware_concurrency();

        if(argc > 1)
        {
            m = boost::lexical_cast<unsigned int>(argv[1]);
        }

        log_trace("m = %d", m);

        std::vector<std::thread> workers;
        for (unsigned int i = 0; i < m; i++)
        {
            workers.push_back(std::thread(thr_func));
        }
        
        std::cin.get();

        std::for_each(workers.begin(), workers.end(), [](std::thread &thr)
        {
            thr.join();
        });

        return 0;

    }
    catch(std::exception& ex)
    {
        log_msg_lvl(c_log::lvl_error, "Exception! Message: %s", ex.what());
    }
}

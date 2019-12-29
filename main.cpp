//
//  main.cpp
//  LW6
//
//  Created by Stanislav Martynov on 17.12.2019.
//  Copyright © 2019 Stanislav Martynov. All rights reserved.
//

#include "search_prototype.hpp"
#include <iostream>
#include <exception>
#include <sstream>
#include <thread>
#include <exception>
#include <vector>
#include <string>
#include <boost/lexical_cast.hpp>
#include "boost/log/trivial.hpp"
auto search_prototypes() -> void
{
    auto thread_id = std::this_thread::get_id();
    auto worker_id = std::to_string(thread_id);
    while(true)
    {
        auto [prototype, valid] = search_prototype();
        if (valid) {
           log_info("Hash is founded: %s", prototype.c_str());
        }
        else {
            log_debug("Debug");
        }
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
        for (unsigned int i = 0; i < m; i++) {
        workers.push_back(std::thread(search_prototypes));
        }
        std::cin.get();

        std::for_each(workers.begin(), workers.end(), [](std::thread &thr)
        {
            thr.join();
        });
    }
    catch (std::exception& ex)
    {
        log_msg_lvl(c_log::lvl_error, "Exception! Message: %s", ex.what());
    }
                          
}

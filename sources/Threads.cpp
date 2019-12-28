//
//  Threads.cpp
//  LW6
//
//  Created by Stanislav Martynov on 17.12.2019.
//  Copyright © 2019 Stanislav Martynov. All rights reserved.
//

#include "Threads.hpp"
#include <sstream>
#include "Log.hpp"

void c_task(std::string id)
{
    std::string prototype = thread::generate_prototype(thread::get_random(5, 255));
    std::string hash = thread::calc_hash(prototype);
    thread::check_hash(hash);
}

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
#include "picosha2.h"

c_task::c_task(std::string id)
    : m_id(id)
{
    std::string prototype = generate_prototype(get_random(5, 255));
    std::string hash = calc_hash(prototype);
    check_hash(hash);
}

std::string c_task::generate_prototype(int length)
{
    std::string result;
    for(int i = 0; i < length; i++)
    {
        result.push_back(get_rand_char());
    }

    return result;
}

std::string c_task::calc_hash(std::string &prot)
{
    std::string result;
    picosha2::hash256_hex_string(prot, result);
    log_trace("[TID: %s] prot = %s \t hash = %s", m_id.c_str(), prot.c_str(), result.c_str());
    return result;
}

int c_task::get_random(int minimum, int maximum)
{
    return minimum + rand() % (maximum - minimum);
}

char c_task::get_rand_char()
{
    return (char)(get_random(33, 126));
}

void c_task::check_hash(std::string &hash)
{
    unsigned int length = 4;
    if(hash.size() > length)
    {
        std::string find_str("0000");
        std::string substr = hash.substr(hash.size()-4, 4);
        std::size_t found = substr.find(find_str);
        if (found!=std::string::npos)
            log_info("[TID: %s] Hash is founded: %s", m_id.c_str(), hash.c_str());
    }
}

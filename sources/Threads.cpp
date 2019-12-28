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
#include <exception>

thread::c_task::c_task(std::string id)
    : m_id(id)
{
    std::string prototype = thread::generate_prototype(get_random(5, 255));
    std::string hash = thread::calc_hash(prototype);
    thread::check_hash(hash);
}
std::string thread::generate_prototype(int length)
{
    std::string result;
    for(int i = 0; i < length; i++)
    {
        result.push_back(thread::get_rand_char());
    }
    return result;
}
std::string thread::calc_hash(std::string& prototype)
{
    std::string result;
    picosha2::hash256_hex_string(prototype, result);
    log_trace("[TID: %s] prot = %s \t hash = %s", m_id.c_str(), prototype.c_str(), result.c_str());
    return result;
}
int thread::get_random(int minimum, int maximum)
{
    if (minimum < maximum)
    {
    return minimum + rand() % (maximum - minimum);
    }
    else
    {
        throw std::invalid_argument("number");
    }
}
char thread::get_rand_char()
{
    return (char)(thread::get_random(33, 126));
}
void thread::check_hash(std::string& hash)
{
    const int length = 4;
    if(hash.size() > length)
    {
        std::string reference("0000");
        std::string substr = hash.substr(hash.size()-4, 4);
        if (substr == reference)
            log_info("[TID: %s] Hash is founded: %s", m_id.c_str(), hash.c_str());
    }
}

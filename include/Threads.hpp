//
//  Threads.hpp
//  LW6
//
//  Created by Stanislav Martynov on 17.12.2019.
//  Copyright © 2019 Stanislav Martynov. All rights reserved.
//

#ifndef Threads_hpp
#define Threads_hpp

#include <string>
#include <thread>
#include "picosha2.h"
#include <exception>
#include <sstream>
#include "Log.hpp"
namespace thread
{
int get_random(int minimum, int maximum)
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
char get_rand_char()
{
    return (char)(get_random(33, 126));
}
std::string generate_prototype(int length)
{
    std::string result;
    for(int i = 0; i < length; i++)
    {
        result.push_back(get_rand_char());
    }
    return result;
}
std::string calc_hash(std::string& prototype)
{
    std::string result;
    picosha2::hash256_hex_string(prototype, result);
    log_trace("prot = %s \t hash = %s", prototype.c_str(), result.c_str());
    return result;
}
void check_hash(std::string& hash)
{
    const int length = 4;
    if(hash.size() > length)
    {
        std::string reference("0000");
        std::string substr = hash.substr(hash.size()-4, 4);
        if (substr == reference)
            log_info("Hash is founded: %s", hash.c_str());
    }
}
}
#endif /* Threads_hpp */

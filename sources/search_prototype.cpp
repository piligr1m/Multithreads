//
//  Threads.cpp
//  LW6
//
//  Created by Stanislav Martynov on 17.12.2019.
//  Copyright © 2019 Stanislav Martynov. All rights reserved.
//

#include "search_prototype.hpp"
#include "log.hpp"
#include <iostream>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include "picosha2.h"

auto generate_random(unsigned int min, unsigned int max) -> unsigned int
{
    if (min < max)
       {
           return min + rand() % (max - min);
       }
       else
       {
           throw std::invalid_argument("number");
       }
}
auto generate_random_char() -> unsigned char
{
    return (char)(generate_random(33, 126));
}
auto generate_prototype(unsigned int length) -> std::string
{
    std::string result;
    for(int i = 0; i < length; i++)
    {
          result.push_back(generate_random_char());
    }
    return result;
}
auto calculate_hash(const std::string& prototype) -> std::string
{
      std::string result;
      picosha2::hash256_hex_string(prototype, result);
      log_trace("prot = %s \t hash = %s", prototype.c_str(), result.c_str());
      return result;
    
}
auto check_hash(const std::string& prototype) -> bool
{
     const unsigned int length = 4;
      if(prototype.size() > length)
        {
            std::string reference("0000");
            std::string substr = prototype.substr(prototype.size()-4, 4);
            if (substr == reference)
            {
                return true;
            }
            else
                return false;
        }
}
auto search_prototype() -> std::pair<std::string, bool>
{
     std::string prototype = generate_prototype(generate_random(5, 255));
     std::string hash = calculate_hash(prototype);
     check_hash(hash);
}



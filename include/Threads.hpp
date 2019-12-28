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
namespace thread
    {
class c_task
{
public:
    c_task(std::string id);
    
private:
    std::string m_id;
};
    std::string generate_prototype(int length);
    std::string calc_hash(std::string& prototype);
    int get_random(int minimum, int maximum);
    char get_rand_char();
    void check_hash(std::string& hash);
    }
#endif /* Threads_hpp */

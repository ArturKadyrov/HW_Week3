#include "generate_collisions.h"

#include <unordered_set>
#include <chrono>
#include "Cat.h"

std::string rand_string ()
{
    int size_str=1+rand()%9;
    std::string str;
    for(int i=0;i<size_str;i++)
    {
        char  h [] = {(char) (65+rand()%57),'\0'};
        str+=std::string (h);
    }
    return str;

}

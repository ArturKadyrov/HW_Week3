#include "generate_collisions.h"

#include <unordered_set>
#include <chrono>
#include "Cat.h"

#include <random>


std::string rand_string ()
{
    std::random_device rd;
    std::mt19937 gen(rd());

    int size_str=1+gen()%79;
    std::string str;
    for(int i=0;i<size_str;i++)
    {
        char  h [] = {(char) (gen()%127),'\0'};
        str+=std::string (h);
    }
    return str;

}

std::size_t generate_collisions (int N)
{
    std::unordered_set < Cat , Cat_Hash , Cat_Equal > cats;

    std::random_device rd;
    std::mt19937 gen(rd());

    for (int i =0 ; i<N; i++)
    {
        std::string name = rand_string();
        int year = gen();
        std::string colour = rand_string();
        int size_before = cats.size();

        cats.insert(Cat(name,year,colour));

        int size_after = cats.size();
        if(size_after==size_before)
        {
            i=i-1;
        }
    }

    std::size_t collisions = 0;
    for (auto i = cats.bucket_count(); i--; )
    {
        if(cats.bucket_size(i)>1)
        {
            collisions+=cats.bucket_size(i)-1;
        }
    }
    return collisions;
}

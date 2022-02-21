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

std::size_t generate_collisions (int N)
{
    std::unordered_set < Cat , Cat_Hash , Cat_Equal > cats;
    srand( time( 0 ) );
    for (int i =0 ; i<N; i++)
    {
        std::string name = rand_string();
        std::string colour = rand_string();
        cats.insert(Cat(name,colour));
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

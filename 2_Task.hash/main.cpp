#include <iostream>
#include "generate_collisions.h"

//#include "hash.h"
//#include "Cat.h"


int main(int argc, char ** argv)
{
    using namespace std;



    int N=2000000;
    for (int i=1350000;i<=N;i+=50000)
    {
        cout<<generate_collisions(i)<<endl;
    }




	return 0;
}

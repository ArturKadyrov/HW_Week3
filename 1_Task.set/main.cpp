#include <iostream>
#include "StopWatch.h"

int * generate_ (int N)
{
    int * Array = new int [N];

   srand( time( 0 ) );
   for (int i =0 ; i<N; i++)
    {
        Array[i] = rand();
    }

    return Array;
}

int main()
{
    using namespace std;

    int N =50;
    int * Array = generate_(N);
    for (int i=0;i<N;i++)
    {
        cout<<Array[i]<<endl;
    }

    delete [] Array;


    return 0;
}

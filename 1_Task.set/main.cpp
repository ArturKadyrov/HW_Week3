#include <iostream>
#include "StopWatch.h"

class Generate
{
private:

    int m_N;
    int * m_Array;

public:

    Generate(int N=10)
    {
        m_N=N;
        m_Array = new int [N];

        srand( time( 0 ) );
        for (int i =0 ; i<N; i++)
        {
            m_Array[i] = rand();
        }
    }
    ~Generate ()
    {
        delete [] m_Array;
    }
    int getN()
    {
        return m_N;
    }

    int operator[] (int index)
    {
        if(index>=m_N || index<0)
            std::cout<<"index error";
        return m_Array[index];
    }

};



int main()
{
    using namespace std;

    int N =50;
    Generate Array (N);

    for (int i=0;i<Array.getN();i++)
    {
        cout<<Array[i]<<endl;
    }




    return 0;
}

#include <iostream>
#include <set>
#include <vector>
#include "StopWatch.h"
#include <algorithm>

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

    int N;
    cout<<"Input number N:"<<endl;
    cin>>N;
    Generate Array (N);


    set<int> Set;
    StopWatch Tset;
    Tset.start();
    //

    for (int i=0;i<N;i++)
    {
        Set.insert(Array[i]);
    }

    //
    Tset.stop();



    vector <int> Vector(N);
    StopWatch Tvector;
    Tvector.start();
    //

    for(int i=0;i<N;i++)
    {
        Vector[i]=Array[i];
    }
    sort(Vector.begin(),Vector.end());

    //
    Tvector.stop();


    cout<<"for set :"<<Tset.print() <<endl;

    cout<<"for vector:"<<Tvector.print()<<endl;

    ///vector выигрывает , причем при Ќ меньше 100000 посто€нна€ примерно равна 2 , при больших значени€х примерно 1.5


    return 0;
}

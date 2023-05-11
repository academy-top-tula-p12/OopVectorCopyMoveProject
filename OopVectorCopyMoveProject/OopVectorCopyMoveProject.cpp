#include <iostream>
#include "Vector.cpp"
#include "Timer.h"

Vector<int> CloneVector(const Vector<int>& v)
{
    Vector<int> cv(v.Size());
    for (int i = 0; i < v.Size(); i++)
        cv[i] = v[i];
    return cv;
}


int main()
{
    Timer timer;

    timer.Reset();

    Vector<int> v(1000000);

    for (int i = 0; i < v.Size(); i++)
        v[i] = i + 1;

    v = CloneVector(v);

    std::cout << timer.Elapsed() << "\n";
    
}

#include <iostream>
#include "TPolinom.h"

int main()
{
    TMonom m(1, 1, 1, 0), m1(1, 1, 1, 1), m2(1, 1, 0, 1), m3(1, 1, 1, 1);
    //std::cin >> m;
    TPolinom p;
    p.InsMonom(m1);
    p.InsMonom(m);
    p.InsMonom(m2);
    p.InsMonom(m3);
    p.Reset();
    p.print();
    return 0;
}


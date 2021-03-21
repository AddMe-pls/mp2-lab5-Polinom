#include <iostream>
#include "TPolinom.h"

int main()
{
    /*TMonom m(1, 1, 1, 0), m1(1, 1, 1, 1), m2(1, 1, 0, 1), m3(1, 1, 1, 1);
    //std::cin >> m;
    TPolinom p;
    p.InsMonom(m1);
    p.InsMonom(m);
    p.InsMonom(m2);
    p.InsMonom(m3);
    p.Reset();
    p.print();*/
    TMonom m1, m2, m3;
    std::cin >> m1>>m2>>m3;
    TPolinom p1;
    p1.InsMonom(m1), p1.InsMonom(m2); p1.InsMonom(m3);
    std::cout << "Polinom 1 size 3: " << p1;
    std::cout << std::endl;
    std::cin >> m1 >> m2 >> m3;
    TPolinom p2;
    p2.InsMonom(m1), p2.InsMonom(m2); p2.InsMonom(m3);
    std::cout << "Polinom 2 size 3: " << p2;
    std::cout << std::endl;
    p1 += p2;
    std::cout << p1;
    return 0;
}


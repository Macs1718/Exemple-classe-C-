#include <iostream>
#include "Polynome.hpp"

int main()
{
    Polynome<float> p(3);
    p[0] = 2;
    p[1] = 3;
    p[2] = 1;
    p[3] = -1;

    Polynome<float>q({1,2,5,4});

    Polynome<float> r(p+q);
    std::cout << "r = " << r << std::endl;
    for ( int i = 0; i < 10; ++i )
    {
        std::cout << "r(" << i << ") = " << r(i) << std::endl;
    }
    std::cout << "dr/dx = " << r.derivate() << std::endl;
    std::cout << "primitive de r : " << r.primitive(0) << std::endl;
    return 0;
}

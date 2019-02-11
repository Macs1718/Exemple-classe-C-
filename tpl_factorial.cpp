#include <iostream>

template<long N> long factorial() { return N*factorial<N-1>(); }
template<> long factorial<0>() { return 1L; }

int main()
{
    std::cout << factorial<5>() << std::endl;
    return 0;
}

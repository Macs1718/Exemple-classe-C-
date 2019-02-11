#include <iostream>

template<int n> constexpr long fibraction = fibraction<n-2> - fibraction<n-1>;
template<> constexpr long fibraction<1> = 1L;
template<> constexpr long fibraction<2> = 2L;

long fib(int n)
{
    if (n==1) return 1;
    if (n==2) return 2;
    return fib(n-2)-fib(n-1);
}

int main()
{
    std::cout << "U32= " << fibraction<32> << std::endl;
    std::cout << "u32 : " << fib(32) << std::endl;
    return 0;
}

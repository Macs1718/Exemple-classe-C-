#include <iostream>
#include <complex>

template<typename K> K pow_n( const K& x0, int n )
{
    if ( n == 0 ) return K(1);
    if ( n%2 == 0) return pow_n(x0*x0,n/2);
    else return x0*pow_n(x0,n-1);
}

template<int n> double ipow_n( const double& x0 )
{
    if ( n%2 == 0) return ipow_n<n/2>(x0*x0);
    else return x0*ipow_n<n-1>(x0);
}
template<> double ipow_n<0>( const double& x0 )
{
    return 1;
}

int main()
{
    std::cout << "3^4 = " << pow_n(3.,4) << std::endl;
    std::cout << "2^5 = " << pow_n(2L,5) << std::endl;
    std::cout << "(1+i)^4 = " << pow_n(std::complex<double>(1,1), 4) << std::endl;
    std::cout << "2^5 = " << ipow_n<5>(2.) << std::endl;

    return 0;
}

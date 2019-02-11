#include <iostream>
#include <cstring>
//#include <vector>

template<typename K1, typename K2> auto max_val( const K1& a, const K2& b ) // ->decltype((a>b ? a : b))
{
    return (a > b ? a : b);
}

std::string max_val( const char* a, const char* b )
{
    return ( strcmp(a,b) > 0 ? a : b);
}

int main()
{
    std::cout << max_val(3,4)
              << ", " << max_val(1.2,3.4) << ", " << max_val('r','f') << std::endl;
    //std::vector<int> res = max_val(std::vector<int>{1,2,3}, std::vector<int>{2,3,4});
    //std::cout << max_val(std::string("tintin"), std::string("milou"))  << std::endl;   
    std::cout << max_val(2.3,4) << std::endl;
    std::cout << max_val("milou", "tintin") << std::endl;
    return 0;
}

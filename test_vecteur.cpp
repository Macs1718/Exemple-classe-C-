// Tests sur les vecteurs geometriques :
# include <iostream>
# include "vecteur.hpp"
# include "point.hpp"
using namespace Geometry;

int main()
{
    point p{ 1., 2., 3.};    
    const vecteur q{0.,1.,2.};
    vecteur v;
    v.x = -2.; v.y = 0.; v.z = 3;
    std::cout << "v = " << v << std::endl;
    point r = p.translate(v);
    std::cout << "r = " << r << std::endl;
    point r2 = p.translate({1.,0.,1.});
    vecteur w{1., 3., 5.};
    vecteur z = v ^ w;

    vecteur n(0.1,0.2);
    std::cout << "n0 = " << n << std::endl;
    n[0] = 3.;
    n[1]= n[0] + 2;

    std::cout << "n = " << n << std::endl;
    for ( auto& x : n ) x += 2;
    std::cout << "n => " << n << std::endl;
    return 0;
}

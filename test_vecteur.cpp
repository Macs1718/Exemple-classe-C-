// Tests sur les vecteurs geometriques :
# include <iostream>
# include "vecteur.hpp"

int main()
{
    vecteur p{ 1., 2., 3.};    
    /*p.set_as_point();*/
    vecteur v;
    v.x = -2.; v.y = 0.; v.z = 3;
/*    vecteur q = p.translate(v);*/
    vecteur w{1., 3., 5.};
    vecteur z = w;
/*    vecteur z = v ^ w;
*/
    vecteur n(0.1,0.2);
}

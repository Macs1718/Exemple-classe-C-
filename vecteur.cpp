#include <cmath>
#include <cassert>
#include "vecteur.hpp"

vecteur::vecteur( double cx, double cy) : x(cx), 
                                          y(cy),
                                          w(0.)
{
    assert(cx*cx+cy*cy<1.);
    z = std::sqrt(1.-cx*cx-cy*cy);
}
                                         

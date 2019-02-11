#include "point.hpp"
#include "vecteur.hpp"
#include <cassert>
#include <cmath>
using namespace Geometry;

point point::translate( const vecteur &t ) const
{
    return {this->x + t.x, this->y + t.y, this->z + t.z};
}

point 
point::operator+( const vecteur &t ) const
{
    point r;
    this->add( t, r );
    return r;
}

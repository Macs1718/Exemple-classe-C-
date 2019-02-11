#include "vecteur.hpp"
#include <cassert>
#include <cmath>
using namespace Geometry;

vecteur::vecteur( double cx, double cy ) : 
    coordhom(cx, cy, 0., false )
{
    assert( cx * cx + cy * cy < 1. );
    z = std::sqrt( 1. - cx * cx - cy * cy );
}

vecteur 
vecteur::operator ^ ( const vecteur& v ) const
{
    return { this->y*v.z - this->z*v.y,
             this->z*v.x - this->x*v.z,
             this->x*v.y - this->y*v.x};
}

#include "vecteur.hpp"
#include <cassert>
#include <cmath>
using namespace Geometry;

vecteur::vecteur( double cx, double cy )
    : x( cx ),
      y( cy ),
      w( 0. )
{
    assert( cx * cx + cy * cy < 1. );
    z = std::sqrt( 1. - cx * cx - cy * cy );
}

vecteur
vecteur::translate( const vecteur& t ) const
{
    if ( this->is_a_point() )
        return {this->x + t.x, this->y + t.y,
                this->z + t.z, true};
    else
        return {this->x, this->y, this->z};
}

vecteur& 
vecteur::operator = ( const vecteur& u )
{
    if ( this != &u )
    {
        this->x = u.x;
        this->y = u.y;
        this->z = u.z;
        this->w = u.w;
    }
    return *this;
}


vecteur 
vecteur::operator ^ ( const vecteur& v ) const
{
    return { this->y*v.z - this->z*v.y,
             this->z*v.x - this->x*v.z,
             this->x*v.y - this->y*v.x};
}

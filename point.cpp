#include "point.hpp"
#include <cassert>
#include <cmath>
# include "vecteur.hpp"
using namespace Geometry;

point
point::translate( const vecteur& t ) const
{
    return {this->x + t.x, this->y + t.y,this->z + t.z};
}

point& 
point::operator = ( const point& u )
{
    if ( this != &u )
    {
        this->x = u.x;
        this->y = u.y;
        this->z = u.z;
    }
    return *this;
}

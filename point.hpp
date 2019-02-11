#ifndef _point_hpp_
#define _point_hpp_
#include <iostream>
#include "coordhom.hpp"
namespace Geometry
{
    class vecteur;
    /**
 * @brief Vecteur géométrique
 * @details Vecteur géométrique en trois dimensions, en coordonnées homogènes.
 * 
 */
    class point : public coordhom
    {
    public:
        using iterator = double *;
        using const_iterator = const double *;

        point() : coordhom(true)
        {
        }
        point( double cx, double cy, double cz) :
            coordhom(cx, cy, cz, true )
        {
            //this->x = cx; this->y = cy;
            //this->z = cz; this->w = 0.;
        }

        point( const point &u ) = default;
        /* : x(u.x), y(u.y),
                                 z(u.z), w(u.w)
    {}*/
        point( point &&u ) = default;

        ~point() = default;

        point translate( const vecteur &t ) const;

        point &
        operator=( const point &u )
        {
            u.copy(*this);
            return *this;
        }

        point &
        operator=( point &&u ) = default;

        virtual std::ostream &
        print( std::ostream &out ) const override
        {
            out << "( ";

            out << this->x << ", " << this->y << ", "
                << this->z;
            out << " )";
            return out;
        }
        point operator + ( const vecteur& t ) const;
    };
}  // namespace Geometry

#endif

#ifndef _coordhom_hpp_
#define _coordhom_hpp_
#include <iostream>

namespace Geometry
{
    /**
 * @brief coordhom géométrique
 * @details coordhom géométrique en trois dimensions, en coordonnées homogènes.
 * 
 */
    class coordhom
    {
    public:
        using iterator = double *;
        using const_iterator = const double *;

        coordhom( bool ispoint = false ) : w( ispoint ? 1 : 0 )
        {
        }
        coordhom( double cx, double cy, double cz,
                 bool ispoint = false )
            : x( cx ), y( cy ), z( cz ), w( ( ispoint ? 1. : 0. ) )
        {
            //this->x = cx; this->y = cy;
            //this->z = cz; this->w = 0.;
        }
        /** Construit un coordhom de norme 1,
        cz est construit de telle sorte que
        ||v||= 1
    */
        coordhom( double cx, double cy );

        coordhom( const coordhom &u ) = default;
        /* : x(u.x), y(u.y),
                                 z(u.z), w(u.w)
    {}*/
        coordhom( coordhom &&u ) = default;

        ~coordhom() = default;
        double x, y, z;


        coordhom &
        operator=( const coordhom &u );

        coordhom &
        operator=( coordhom &&u ) = default;

        double operator[]( int i ) const
        {
            if ( i == 0 ) return this->x;
            if ( i == 1 ) return this->y;
            if ( i == 2 ) return this->z;
            return 0;
        }

        double &operator[]( int i )
        {
            if ( i == 0 ) return this->x;
            if ( i == 1 ) return this->y;
            return this->z;
        }

        iterator begin() { return &this->x; }
        iterator end() { return &this->w; }

        const_iterator begin() const
        {
            return &this->x;
        }
        const_iterator end() const
        {
            return &this->w;
        }

        virtual std::ostream &
        print( std::ostream &out ) const = 0;

    private:
        double w;
    };

    inline std::ostream &operator<<( std::ostream &out,
                                     const coordhom &v )
    {
        return v.print( out );
    }
}  // namespace Geometry

#endif

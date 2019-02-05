#ifndef _vecteur_hpp_
#define _vecteur_hpp_
#include <iostream>

namespace Geometry
{
    /**
 * @brief Vecteur géométrique
 * @details Vecteur géométrique en trois dimensions, en coordonnées homogènes.
 * 
 */
    class vecteur
    {
    public:
        using iterator = double *;
        using const_iterator = const double *;

        vecteur()
            : w( 0. )
        {
        }
        vecteur( double cx, double cy, double cz,
                 bool ispoint = false )
            : x( cx ), y( cy ), z( cz ), w( ( ispoint ? 1. : 0. ) )
        {
            //this->x = cx; this->y = cy;
            //this->z = cz; this->w = 0.;
        }
        /** Construit un vecteur de norme 1,
        cz est construit de telle sorte que
        ||v||= 1
    */
        vecteur( double cx, double cy );

        vecteur( const vecteur &u ) = default;
        /* : x(u.x), y(u.y),
                                 z(u.z), w(u.w)
    {}*/
        vecteur( vecteur &&u ) = default;

        ~vecteur() = default;
        double x, y, z;

        void set_as_point()
        {
            this->w = 1.;
        }

        bool is_a_point() const
        {
            return ( this->w == 1. );
        }

        vecteur translate( const vecteur &t ) const;

        vecteur operator^( const vecteur &v ) const;

        vecteur &
        operator=( const vecteur &u );

        vecteur &
        operator=( vecteur &&u ) = default;

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

        std::ostream &print( std::ostream &out ) const
        {
            if ( is_a_point() )
                out << "( ";
            else
                out << "[ ";

            out << this->x << ", " << this->y << ", "
                << this->z;
            if ( is_a_point() )
                out << " )";
            else
                out << " ]";
            return out;
        }

    private:
        double w;
    };

    inline std::ostream &operator<<( std::ostream &out,
                                     const vecteur &v )
    {
        return v.print( out );
    }
}  // namespace Geometry

#endif

#ifndef _vecteur_hpp_
#define _vecteur_hpp_
#include <iostream>
#include "coordhom.hpp"
namespace Geometry
{
    /**
 * @brief Vecteur géométrique
 * @details Vecteur géométrique en trois dimensions, en coordonnées homogènes.
 * 
 */
    class vecteur : public coordhom
    {
    public:
        using iterator = double *;
        using const_iterator = const double *;

        vecteur() : coordhom(false)
        {
        }
        vecteur( double cx, double cy, double cz) :
            coordhom(false)
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

        vecteur operator^( const vecteur &v ) const;

        vecteur &
        operator=( const vecteur &u );

        vecteur &
        operator=( vecteur &&u ) = default;


        virtual std::ostream &
        print( std::ostream &out ) const override
        {
            out << "[ ";

            out << this->x << ", " << this->y << ", "
                << this->z;
            out << " ]";
            return out;
        }

    };
}  // namespace Geometry

#endif

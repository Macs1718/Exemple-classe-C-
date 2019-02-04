#ifndef _vecteur_hpp_
#define _vecteur_hpp_

class vecteur
{
public:
    vecteur() : w(0.)
    {}
    vecteur( double cx, double cy, double cz) :
        x(cx), y(cy), z(cz), w(0.)
    {
        //this->x = cx; this->y = cy; 
        //this->z = cz; this->w = 0.;
    }
    /** Construit un vecteur de norme 1,
        cz est construit de telle sorte que
        ||v||= 1
    */
    vecteur( double cx, double cy);

    vecteur(const vecteur& u ) = default;
                            /* : x(u.x), y(u.y),
                                 z(u.z), w(u.w)
    {}*/
    vecteur( vecteur&& u ) = delete;
    
    ~vecteur() = default;
    double x,y,z;

private:
    double w;
};

#endif

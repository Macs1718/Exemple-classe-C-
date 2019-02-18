#ifndef _POLYNOME_HPP_
#define _POLYNOME_HPP_
# include <vector>
# include <cassert>

template<typename K>
class Polynome
{
public:
    using container = std::vector<K>;

    Polynome() = default;
    Polynome( int deg ) : _coeff(deg+1, K(0))
    {}
    // p = Polynome({1.,2.,0.,3.,1.}); // 1. + 2x + 3x^3 + x^4
    Polynome( const std::initializer_list<K>& coefs) : _coeff(coefs)
    {}
    Polynome(const Polynome& p) = default;
    Polynome( Polynome&& p ) = default;
    ~Polynome() = default;

    int degree() const { return _coeff.size()-1; }
    Polynome operator + ( const Polynome& p ) const
    {
        Polynome r(std::max(p.degree(), this->degree()));
        for ( int i = 0; i <= std::min(p.degree(), this->degree());
             ++i)
            r[i] = p[i] + this->_coeff[i];
        if ( this->degree() > p.degree() )
            for ( int i = p.degree() + 1; i <= this->degree();
                   ++i )
                r[i] = this->_coeff[i];
        else if ( p.degree() > this->degree() )
        {
            for ( int i = this->degree()+1; i <= p.degree();
                  ++i )
                r[i] = p[i];
        }
        return r;
    }

    K& operator []( int i )
    {
        assert(i>=0);// Supprime si option -DNDEBUG mis à la compilation
        assert(i<=degree());        
        return _coeff[i];
    }

    K operator []( int i ) const
    {
        assert(i>=0);
        assert(i<=degree());        
        return _coeff[i];
    }

    Polynome derivate() const;
    Polynome primitive( const K& p0 ) const;

private:
    container _coeff;
};

#endif

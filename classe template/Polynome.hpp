#ifndef _POLYNOME_HPP_
#define _POLYNOME_HPP_
# include <vector>
# include <cassert>
# include <iostream>

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

    Polynome derivate() const
    {
        Polynome dP(degree()-1);
        for ( int i = 1; i <= degree(); ++i )
            dP[i-1] = i*_coeff[i];
        return dP;
    }

    Polynome primitive( const K& p0 = K(0) ) const
    {
        Polynome primP(degree()+1);
        primP[0] = p0;
        for ( int i = 0; i <= degree(); ++i )
            primP[i+1] = _coeff[i]/K(i+1);
        return primP;
    }

    template<typename K2>
    auto operator() (const K2& x) const
    {
        using K3 = decltype(_coeff[0]*x);
        K3 res = _coeff[0];
        K2 xn  = x;
        for ( int i = 1; i <= degree(); ++i )
        {
            res += K3(_coeff[i])*xn;
            xn *= x;
        }
        return res;
    }

private:
    container _coeff;
};

template<typename K> std::ostream& 
operator << ( std::ostream& out, const Polynome<K>& p )
{
    out << p[0];
    for ( int i = 1; i <= p.degree(); ++i )
    {
        if ( p[i] > 0 )
        {
            out << "+" << p[i] << ".x^{" << i << "}";
        }
        else if ( p[i] < 0 )
        {
            out << "-" << p[i] << ".x^{" << i << "}";
        }
    }
    return out;
}


#endif

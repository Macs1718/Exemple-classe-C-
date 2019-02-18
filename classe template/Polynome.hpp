#ifndef _POLYNOME_HPP_
#define _POLYNOME_HPP_
# include <vector>

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
    Polynome operator + ( const Polynome& p ) const;

    Polynome derivate() const;
    Polynome primitive( const K& p0 ) const;
    
private:
    container _coeff;
};

#endif

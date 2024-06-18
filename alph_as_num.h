//
// Created by paul on 17.6.24.
//

#ifndef ALPH_AS_NUM_ALPH_AS_NUM_H
#define ALPH_AS_NUM_ALPH_AS_NUM_H

#include <string>
#include <stdexcept>

class alph_as_num {
public:
    alph_as_num() = default;
    alph_as_num( const std::string &s );
    alph_as_num( const alph_as_num& other );
    alph_as_num( const char* ch );
    alph_as_num &operator = ( const alph_as_num &b );
    alph_as_num &operator = ( const std::string &s );
    alph_as_num &operator = ( const char* s );

    ~alph_as_num() = default;

    friend alph_as_num operator + ( const alph_as_num &a, const alph_as_num &b );
    alph_as_num operator += ( const alph_as_num &b );
    friend alph_as_num operator - ( const alph_as_num &a, const alph_as_num &b );
    alph_as_num operator -= ( const alph_as_num &b );
    friend alph_as_num operator * ( const alph_as_num &a, const alph_as_num &b );
    alph_as_num operator *= ( const alph_as_num &b );
    friend alph_as_num operator / ( const alph_as_num &a, const alph_as_num &b );
    alph_as_num operator /= ( const alph_as_num &b );

    friend bool operator == ( const alph_as_num &a , const alph_as_num &b ) ;
    friend auto operator <=> ( const alph_as_num &a , const alph_as_num &b)  {
        return a.num_repr <=> b.num_repr;
    }

    friend std::istream &operator>> ( std::istream &stream , alph_as_num& a);
    void print ( std::ostream& stream ) ;
    friend std::ostream &operator<< ( std::ostream &stream , alph_as_num& a);

private:
    std::string str_repr;
    unsigned num_repr;
};

#endif //ALPH_AS_NUM_ALPH_AS_NUM_H

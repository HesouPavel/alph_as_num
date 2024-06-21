//
// Created by paul on 17.6.24.
//

#ifndef ALPH_AS_NUM_ALPH_INT_H
#define ALPH_AS_NUM_ALPH_INT_H

#include <string>
#include <stdexcept>


/**
 * @brief can be used to process integer operations with numeral system consisting of letters a-z
 * holds and updates the string representation as well as the equivalent integer value,
 * which allows for faster computing
*/
class alph_int {
public:
    alph_int() = default;
    alph_int(const std::string &s );
    alph_int(const alph_int& other );
    alph_int(const char* ch );
    alph_int &operator = (const alph_int &b );
    alph_int &operator = (const std::string &s );
    alph_int &operator = (const char* s );

    ~alph_int() = default;


    /* Using the friend keyword allows operator functions to directly access private members.
     * Allowing encapsulation and avoiding the need for public accessors.
     * It also maintains the natural symmetry and intuitive behavior of binary operators.
     */
    alph_int operator + ( const alph_int &b );
    friend alph_int operator + (const alph_int &a, const alph_int &b );
    alph_int operator += (const alph_int &b );
    friend alph_int operator - (const alph_int &a, const alph_int &b );
    alph_int operator -= (const alph_int &b );
    friend alph_int operator * (const alph_int &a, const alph_int &b );
    alph_int operator *= (const alph_int &b );
    friend alph_int operator / (const alph_int &a, const alph_int &b );
    alph_int operator /= (const alph_int &b );

    friend bool operator == (const alph_int &a , const alph_int &b ) = default;
    friend bool operator == (const alph_int &a , const std::string &s ) ;
    friend bool operator == (const alph_int &a , const char* s ) ;
    friend auto operator <=> (const alph_int &a , const alph_int &b)  {
        return a.num_repr <=> b.num_repr;
    }

    friend std::istream &operator>> (std::istream &stream , alph_int& a);
    void print ( std::ostream& stream ) ;
    friend std::ostream &operator<< (std::ostream &stream , alph_int& a);

private:
    std::string str_repr;
    unsigned num_repr;
};

#endif //ALPH_AS_NUM_ALPH_INT_H

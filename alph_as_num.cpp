//
// Created by paul on 17.6.24.
//

#include "alph_as_num.h"

std::string num_to_str ( unsigned x ) {
    std::string ret;
    while (x > 0) {
        int remainder = (x - 1) % 26;
        char letter = 'A' + remainder;
        // places the new letter to the front
        ret = letter + ret;
        x = (x - 1) / 26;
    }
    return ret;
}



alph_as_num::alph_as_num( const std::string &s ) {
    int num = 0;
    for ( auto ch : s ) {
        if ( !isalpha(ch) ) throw std::invalid_argument("Not alphabetic input.");
        ch = toupper(ch);
        num *= 26;
        num += ch - 'A' + 1;
    }
    str_repr = s;
    num_repr = num;
}
alph_as_num::alph_as_num( const alph_as_num& other ) {
    str_repr = other.str_repr;
    num_repr = other.num_repr;
}
alph_as_num::alph_as_num(const char *ch) {
    std::string string(ch);
    *this = string;
}
alph_as_num& alph_as_num::operator= (const alph_as_num &other) {
    str_repr = other.str_repr;
    num_repr = other.num_repr;
    return *this;
}

alph_as_num &alph_as_num::operator= (const std::string &s) {
    *this = alph_as_num(s);
    return *this;
}
alph_as_num &alph_as_num::operator= ( const char* ch ) {
    std::string string(ch);
    *this = string;
    return *this;
}

//++++++++++++++++++++++++++++++++++++++++
alph_as_num operator+ ( const alph_as_num &a, const alph_as_num &b ) {
    return num_to_str(a.num_repr + b.num_repr);
}
alph_as_num alph_as_num::operator+= ( const alph_as_num &b ){
    *this = alph_as_num(num_to_str(num_repr + b.num_repr));
    return *this;
}
//-----------------------------------------
alph_as_num operator- ( const alph_as_num &a, const alph_as_num &b ) {
    return num_to_str(a.num_repr - b.num_repr );
}
alph_as_num alph_as_num::operator-= ( const alph_as_num &b ){
    *this = alph_as_num(num_to_str(num_repr - b.num_repr));
    return *this;
}
//******************************************
alph_as_num operator* ( const alph_as_num &a, const alph_as_num &b ) {
    return num_to_str(a.num_repr * b.num_repr );
}
alph_as_num alph_as_num::operator*= ( const alph_as_num &b ){
    *this = alph_as_num(num_to_str(num_repr * b.num_repr));
    return *this;
}
// /////////////////////////////////////////
alph_as_num operator/ ( const alph_as_num &a, const alph_as_num &b ) {
    return num_to_str(a.num_repr / b.num_repr );
}
alph_as_num alph_as_num::operator/= ( const alph_as_num &b ){
    *this = alph_as_num(num_to_str(num_repr / b.num_repr));
    return *this;
}

bool operator==


// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
std::istream &operator>> ( std::istream& stream, alph_as_num &a ){
    std::string str; stream >> str;
    a = alph_as_num(str);
    return stream;
}
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
std::ostream &operator<< ( std::ostream& stream, alph_as_num &a ){
    a.print(stream);
    return stream;
}
void alph_as_num::print(std::ostream &stream) {
    stream << str_repr;
}

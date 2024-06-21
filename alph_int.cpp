//
// Created by paul on 17.6.24.
//

#include "alph_int.h"

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

alph_int::alph_int(const std::string &s ) {
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
alph_int::alph_int(const alph_int& other ) {
    str_repr = other.str_repr;
    num_repr = other.num_repr;
}
alph_int::alph_int(const char *ch) {
    std::string string(ch);
    *this = string;
}
alph_int& alph_int::operator= (const alph_int &other) {
    str_repr = other.str_repr;
    num_repr = other.num_repr;
    return *this;
}

alph_int &alph_int::operator= (const std::string &s) {
    *this = alph_int(s);
    return *this;
}
alph_int &alph_int::operator= (const char* ch ) {
    std::string string(ch);
    *this = string;
    return *this;
}

//++++++++++++++++++++++++++++++++++++++++
alph_int alph_int::operator+ (const alph_int &a) {
    return num_to_str(num_repr + a.num_repr );
}
alph_int operator+ (const alph_int &a, const alph_int &b ) {
    return num_to_str(a.num_repr + b.num_repr);
}
alph_int alph_int::operator+= (const alph_int &b ){
    *this = alph_int(num_to_str(num_repr + b.num_repr));
    return *this;
}
//-----------------------------------------
alph_int operator- (const alph_int &a, const alph_int &b ) {
    return num_to_str(a.num_repr - b.num_repr );
}
alph_int alph_int::operator-= (const alph_int &b ){
    *this = alph_int(num_to_str(num_repr - b.num_repr));
    return *this;
}
//******************************************
alph_int operator* (const alph_int &a, const alph_int &b ) {
    return num_to_str(a.num_repr * b.num_repr );
}
alph_int alph_int::operator*= (const alph_int &b ){
    *this = alph_int(num_to_str(num_repr * b.num_repr));
    return *this;
}
// /////////////////////////////////////////
alph_int operator/ (const alph_int &a, const alph_int &b ) {
    return num_to_str(a.num_repr / b.num_repr );
}
alph_int alph_int::operator/= (const alph_int &b ){
    *this = alph_int(num_to_str(num_repr / b.num_repr));
    return *this;
}

bool operator== (const alph_int &a , const std::string &s ) {
    std::string upper;
    for ( auto &x : s ){
        upper.push_back(toupper(x));
    }
    return a.str_repr == upper;
}
bool operator== (const alph_int &a , const char * s ) {
    std::string upper;
    for ( auto &x : std::string(s) ){
        upper.push_back(toupper(x));
    }
    return a.str_repr == upper;
}


// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
std::istream &operator>> (std::istream& stream, alph_int &a ){
    std::string str; stream >> str;
    a = alph_int(str);
    return stream;
}
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
std::ostream &operator<< (std::ostream& stream, alph_int &a ){
    a.print(stream);
    return stream;
}
void alph_int::print(std::ostream &stream) {
    stream << str_repr;
}

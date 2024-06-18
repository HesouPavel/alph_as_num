#include <iostream>
#include <string>
#include <cassert>
#include "alph_as_num.h"

int main () {
    alph_as_num a("abc");
    a.print(std::cout);
    alph_as_num b("aaa");
    alph_as_num c = "aaa";
    assert(a != b);
    assert(!(a == b));
    assert(b == c);
    alph_as_num d = a + b;
    assert(d == "bcd");
    return EXIT_SUCCESS;
}


//
// Created by paul on 17.6.24.
//

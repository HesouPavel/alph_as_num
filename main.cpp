#include <iostream>
#include <string>
#include <cassert>
#include "alph_int.h"

int main () {
    alph_int a("abc");
    alph_int b("aaa");
    alph_int c = "aaa";
    assert(a != b);
    assert(!(a == b));
    assert(b == c);
    alph_int d = a + b;
    assert(d == "bcd");
    1+'a';
    return EXIT_SUCCESS;
}


//
// Created by paul on 17.6.24.
//

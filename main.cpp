//
//  main.cpp
//  Fraction
//
//  Created by Gabriel Kapach on 18/09/2017.
//  Copyright © 2017 Gabriel Kapach. All rights reserved.
//

#include <iostream>
#include "Fraction.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    Fraction frac = Fraction(1, 2);
    Fraction frac2 = 2 * frac;
    
    std::cout << frac2;
    std::cout << 1 + (Fraction)2.5;
    std::cout << Fraction(2.5);
    std::cout << Fraction(6, 36);
    std::cout << Fraction(2, 4);
    std::cout << Fraction(2, 4) + Fraction(1, 4);
    
    try {
        Fraction(10, 0);
    } catch (DivisionByZeroException e) {
        e.print();
    }
    
    try {
        frac / 0;
    } catch (DivisionByZeroException e) {
        e.print();
    }
    
    return 0;
}

//
//  Fraction.hpp
//  Fraction
//
//  Created by Gabriel Kapach on 18/09/2017.
//  Copyright © 2017 Gabriel Kapach. All rights reserved.
//

#ifndef Fraction_hpp
#define Fraction_hpp

#include <stdio.h>
#include <iostream>
#include <cmath>
#include "DivisionByZeroException.hpp"

class Fraction {
    
public:
    Fraction(int nominator, int denominator);
    Fraction(double num);
    Fraction(float num);
    Fraction(int num);
//    ~Fraction();
    
    Fraction operator- (const Fraction & frac);
    
    Fraction operator* (const int num) const;
    Fraction operator/ (const int num) const;
    Fraction operator+ (const int num) const;
    Fraction operator- (const int num) const;
    
    operator float () const;
    operator int () const;
    
    friend std::ostream& operator<< (std::ostream & os, const Fraction & frac);
    
    friend Fraction operator* (const Fraction & frac1, const Fraction & frac2);
    friend Fraction operator/ (const Fraction & frac1, const Fraction & frac2);
    friend Fraction operator+ (const Fraction & frac1, const Fraction & frac2);
    friend Fraction operator- (const Fraction & frac1, const Fraction & frac2);
    
    friend Fraction operator* (int num, const Fraction & frac);
    friend Fraction operator/ (int num, const Fraction & frac);
    friend Fraction operator+ (int num, const Fraction & frac);
    friend Fraction operator- (int num, const Fraction & frac);
    
    int getNominator() const;
    int getDenominator() const;
    
private:
    int m_nominator;
    int m_denominator;
    
    unsigned int gcd(unsigned int u, unsigned int v);
};

#endif /* Fraction_hpp */

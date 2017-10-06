//
//  Fraction.cpp
//  Fraction
//
//  Created by Gabriel Kapach on 18/09/2017.
//  Copyright © 2017 Gabriel Kapach. All rights reserved.
//

#include "Fraction.hpp"

Fraction::Fraction(int nominator, int denominator) {
    if (denominator == 0) {
        throw DivisionByZeroException();
    }
    
    unsigned int gcd_ = gcd(nominator, denominator);
    
    m_nominator = nominator / gcd_;
    m_denominator = denominator / gcd_;
}

Fraction::Fraction(double num) {
    double integral = std::floor(num);
    double frac = num - integral;
    
    const long precision = 1000000000;
    
    unsigned int gcd_ = gcd(round(frac * precision), precision);
    
    m_denominator = precision / gcd_;
    m_nominator = (round(frac * precision) / gcd_) + integral * m_denominator;
}

Fraction::Fraction(float num) {
    float integral = std::floor(num);
    float frac = num - integral;
    
    const long precision = 10000000;
    
    unsigned int gcd_ = gcd(round(frac * precision), precision);
    
    m_denominator = precision / gcd_;
    m_nominator = (round(frac * precision) / gcd_) + integral * m_denominator;
}

Fraction::Fraction(int num) {
    m_nominator = num;
    m_denominator = 1;
}

int Fraction::getNominator() const {
    return m_nominator;
}

int Fraction::getDenominator() const {
    return m_denominator;
}

Fraction Fraction::operator- (const Fraction & frac) {
    return Fraction(-frac.getNominator(), frac.getDenominator());
}

Fraction Fraction::operator* (const int num) const {
    return Fraction(m_nominator * num, m_denominator);
}

Fraction Fraction::operator/ (const int num) const {
    if (num == 0) {
        throw DivisionByZeroException();
    }
    
    return Fraction(m_nominator, m_denominator * num);
}

Fraction Fraction::operator+ (const int num) const {
    return Fraction(m_nominator + num * m_denominator, m_denominator);
}

Fraction Fraction::operator- (const int num) const {
    return Fraction(m_nominator - num * m_denominator, m_denominator);
}

Fraction::operator float () const {
    return (float)m_nominator / (float)m_denominator;
}

Fraction::operator int () const {
    return m_nominator / m_denominator;
}

std::ostream& operator<< (std::ostream & os, const Fraction & frac) {
    return os << frac.getNominator() << "/" << frac.getDenominator() << "\n";
}

Fraction operator* (const Fraction & frac1, const Fraction & frac2) {
    return Fraction(frac1.getNominator() * frac2.getNominator(), frac1.getDenominator() * frac2.getDenominator());
}

Fraction operator/ (const Fraction & frac1, const Fraction & frac2) {
    return Fraction(frac1.getNominator() * frac2.getDenominator(), frac1.getDenominator() * frac2.getNominator());
}

Fraction operator+ (const Fraction & frac1, const Fraction & frac2) {
    return Fraction(frac1.getNominator() * frac2.getDenominator() + frac2.getNominator() * frac1.getDenominator(), frac1.getDenominator() * frac2.getDenominator());
}

Fraction operator- (const Fraction & frac1, const Fraction & frac2) {
    return Fraction(frac1.getNominator() * frac2.getDenominator() - frac2.getNominator() * frac1.getDenominator(), frac1.getDenominator() * frac2.getDenominator());
}

Fraction operator* (int num, const Fraction & frac) {
    return frac * num;
}

Fraction operator/ (int num, const Fraction & frac) {
    return frac / num;
}

Fraction operator+ (int num, const Fraction & frac) {
    return frac + num;
}

Fraction operator- (int num, const Fraction & frac) {
    return Fraction(num, 1) - frac;
}

// Returns the greatest common divisor of 2 numbers using the Stein's algorithm 
unsigned int Fraction::gcd(unsigned int u, unsigned int v) {
    // simple cases (termination)
    if (u == v)
        return u;
    
    if (u == 0)
        return v;
    
    if (v == 0)
        return u;
    
    // look for factors of 2
    if (~u & 1) // u is even
    {
        if (v & 1) // v is odd
            return gcd(u >> 1, v);
        else // both u and v are even
            return gcd(u >> 1, v >> 1) << 1;
    }
    
    if (~v & 1) // u is odd, v is even
        return gcd(u, v >> 1);
    
    // reduce larger argument
    if (u > v)
        return gcd((u - v) >> 1, v);
    
    return gcd((v - u) >> 1, u);
}

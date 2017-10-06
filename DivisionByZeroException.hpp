//
//  DivisionByZeroException.hpp
//  Fraction
//
//  Created by Gabriel Kapach on 18/09/2017.
//  Copyright © 2017 Gabriel Kapach. All rights reserved.
//

#ifndef DivisionByZeroException_hpp
#define DivisionByZeroException_hpp

#include <stdio.h>
#include <iostream>

class DivisionByZeroException {
public:
    const char * message;
    
    DivisionByZeroException();
    DivisionByZeroException(const char * message);
    
    void print();
};

#endif /* DivisionByZeroException_hpp */

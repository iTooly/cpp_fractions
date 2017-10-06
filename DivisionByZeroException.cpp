//
//  DivisionByZeroException.cpp
//  Fraction
//
//  Created by Gabriel Kapach on 18/09/2017.
//  Copyright © 2017 Gabriel Kapach. All rights reserved.
//

#include "DivisionByZeroException.hpp"

DivisionByZeroException::DivisionByZeroException() {
    this->message = "Division of number by zero.";
}

DivisionByZeroException::DivisionByZeroException(const char * message) {
    this->message = message;
}

void DivisionByZeroException::print() {
    std::cout << message << "\n";
}

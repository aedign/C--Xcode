//
//  SectionNumbers.hpp
//
//  Assignment 3
//  CS3305
//  Created by Andres Di Gregorio on 10/26/19.
//  Copyright © 2019 Andres Di Gregorio. All rights reserved.
//

#ifndef SectionNumbers_hpp
#define SectionNumbers_hpp
#include <string>
#include <iostream>
#include <stdio.h>

using namespace std;

class SectionNumbers{

public:

    void numbers(ostream& outs, const string& prefix, unsigned int levels);
};

#endif /* SectionNumbers_hpp */

//
//  SectionNumbers.cpp
//
//  Assignment 3
//  CS3305
//  Created by Andres Di Gregorio on 10/26/19.
//  Copyright © 2019 Andres Di Gregorio. All rights reserved.
//
#include "SectionNumbers.hpp"

void SectionNumbers::numbers(ostream& outs, const string& prefix, unsigned int levels){
    
    // The string "s" is used to add numbers to the passed string called "prefix"
    string s;
    
    // Precondition: if level equals 0, then an entire section of numbers has been added to the string,
    // so the string is printed.
    if(levels == 0){
        outs << prefix << endl;
        return;
    }
    
    // Postcondition: The for loop adds a numbers followed by a "." from 1 to 9 to the string. The size of the int "levels"
    // determines the amount of sections that will be added to the string.
    else{
        for(int i = 1; i < 10; i++){
            s =(prefix + to_string(i)) + ".";
            numbers(outs,s,levels-1);
        }
    }
}


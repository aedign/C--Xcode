//
//  FractalPattern.cpp
//
//  Assignment 3
//  CS3305
//  Created by Andres Di Gregorio on 10/26/19.
//  Copyright © 2019 Andres Di Gregorio. All rights reserved.
//

#include "FractalPattern.hpp"

void FractalPattern::pattern(ostream& outs, unsigned int n, unsigned int i){
    
    // Precondition: If "n" equals 1, that means that only one star will be printed.
    // A for loop verifies that there are "i" spaces before the star.
    
    if (n==1){
        for (int y = 0; y < i; y++)
        outs << " ";

        outs << "* " << endl;
    }
    
    //Postcondition: A pattern of starts will be printed while "n" is greater than one but
    // is never greater than the value passed in the main. The longest line of starts of length "n" will be printed in the middle of the pattern with "i" spaces before it.
    else{
        pattern(outs,n/2,i);
        
        for (int y = 0; y < i; y++)
                 outs << " ";

        for(int x = 0; x < n; x++)
            outs << "* ";
        
        outs << endl;

        pattern(outs, n/2,i+n);
    }
    
}

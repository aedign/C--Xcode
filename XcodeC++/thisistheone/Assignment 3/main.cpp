//
//  main.cpp
//
//  Assignment 3
//  CS3305
//  Created by Andres Di Gregorio on 10/26/19.
//  Copyright © 2019 Andres Di Gregorio. All rights reserved.
//

#include <iostream>
#include "SectionNumbers.hpp"
#include "FractalPattern.hpp"
using namespace std;


int main(int argc, const char * argv[]) {
    
    cout << "Part 1: Section Numbers " << endl;
   SectionNumbers test;
    string word = "hola";
    
    test.numbers(cout, word, 2);
    
    cout << endl;
    cout << "Part 2: Fractal Pattern " << endl;
    
    FractalPattern test2;
    
    test2.pattern(cout, 8, 0);
    
}

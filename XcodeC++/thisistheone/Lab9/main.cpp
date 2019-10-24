//
//  main.cpp
//  Lab9
//
//  Created by Andres Di Gregorio on 10/24/19.
//  Copyright © 2019 Andres Di Gregorio. All rights reserved.
//

#include <stdio.h>
#include "stack_pair.h"
#include <iostream>

using namespace std;
 void test1(){
    
    stack_pair<int> stackInt;
     
     int numbersA[4] = {1,2,3,4};
     
     int numbersB[4] = {9,8,7,6};
    
    stackInt.push_a(numbersA[0]);
    stackInt.push_a(numbersA[1]);
    stackInt.push_a(numbersA[2]);
    stackInt.push_a(numbersA[3]);

     stackInt.push_b(numbersB[0]);
     stackInt.push_b(numbersB[1]);
     stackInt.push_b(numbersB[2]);
     stackInt.push_b(numbersB[3]);


  
     stackInt.print();
     
     
}

int main(){

    test1();
}

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
     
     // Numbers to be pushed into A
     int numbersA[4] = {1,2,3,4};
    
    stackInt.push_a(numbersA[0]);
    stackInt.push_a(numbersA[1]);
    stackInt.push_a(numbersA[2]);
    stackInt.push_a(numbersA[3]);

     
    // Numbers to be pushed into B
    int numbersB[4] = {9,8,7,6};
     
    stackInt.push_b(numbersB[0]);
    stackInt.push_b(numbersB[1]);
    stackInt.push_b(numbersB[2]);
    stackInt.push_b(numbersB[3]);
     
     // If the loops are succesful, they should pop 4 numbers on each stack
     
     //popping all values from A
     int popCountA=0;
     for(int i = (sizeof(numbersA)/sizeof(numbersA[0])-1); i >= 0; i--){
         if(numbersA[i] == stackInt.pop_a()){
             popCountA++;
         }
     }
     
     //popping all values from B
     int popCountB=0;
     for(int i = (sizeof(numbersB)/sizeof(numbersB[0])-1); i >= 0; i--){
        if(numbersB[i] == stackInt.pop_b()){
            popCountB++;
        }
         }
     
     if(popCountA && popCountB){
         cout << "Test 1 passed" << endl;
     }
     else{
         cout << "Test 1 failed" << endl;
     }
}

void test2(){
    
    stack_pair<int> stackInt;
     
     // Numbers to be pushed into A
     int numbersA[15] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    
     for(int i = 0; i < (sizeof(numbersA)/sizeof(numbersA[0])); i++){
         stackInt.push_a(numbersA[i]);
        }

     
    // Numbers to be pushed into B
    int numbersB[15] = {16,17,18,19,20,21,22,23,24,25,26,27,28,29,30};
     
    for(int i = 0; i < (sizeof(numbersB)/sizeof(numbersB[0])); i++){
        stackInt.push_b(numbersB[i]);
    }
    
     // If the loops are succesful, they should pop 15 numbers on each stack
     
     //popping all values from A
     int popCountA=0;
     for(int i = (sizeof(numbersA)/sizeof(numbersA[0])-1); i >= 0; i--){
         if(numbersA[i] == stackInt.pop_a()){
             popCountA++;
         }
     }
     
     //popping all values from B
     int popCountB=0;
     for(int i = (sizeof(numbersB)/sizeof(numbersB[0])-1); i >= 0; i--){
        if(numbersB[i] == stackInt.pop_b()){
            popCountB++;
        }
         }
     
     if(popCountA && popCountB){
         cout << "Test 2 passed" << endl;
     }
     else{
         cout << "Test 2 failed" << endl;
     }
    
}

void test3(){

    // TEST 3 SHOULD FAIL, SINCE MORE NUMBERS THAN THE CAPCITY ALLOWS ARE ADDED
    stack_pair<int> stackInt;
     
     // Numbers to be pushed into A
     int numbersA[16] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    
     for(int i = 0; i < (sizeof(numbersA)/sizeof(numbersA[0])); i++){
         stackInt.push_a(numbersA[i]);
        }

     
    // Numbers to be pushed into B
    int numbersB[16] = {16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31};
     
    for(int i = 0; i < (sizeof(numbersB)/sizeof(numbersB[0])); i++){
        stackInt.push_b(numbersB[i]);
    }
     
     // If the loops are succesful, they should pop 15 numbers on each stack
     
     //popping all values from A
     int popCountA=0;
     for(int i = (sizeof(numbersA)/sizeof(numbersA[0])-1); i >= 0; i--){
         if(numbersA[i] == stackInt.pop_a()){
             popCountA++;
         }
     }
     
     //popping all values from B
     int popCountB=0;
     for(int i = (sizeof(numbersB)/sizeof(numbersB[0])-1); i >= 0; i--){
        if(numbersB[i] == stackInt.pop_b()){
            popCountB++;
        }
         }
     
     if(popCountA && popCountB){
         cout << "Test 2 passed" << endl;
     }
     else{
         cout << "Test 2 failed" << endl;
     }
    
}

void test4(){
    
    // TEST 4 SHOULD FAIL, SINCE THE STACKS ARE EMPTY AND NOTHING CAN BE POPPED
    stack_pair<int> stackInt;
    
    stackInt.pop_a();
    stackInt.pop_b();
}


int main(){

    test1();
    
    test2();
    
     // TEST 3 SHOULD FAIL, SINCE MORE NUMBERS THAN THE CAPCITY ALLOWS ARE ADDED
    test3();
    
    // TEST 4 SHOULD FAIL, SINCE THE STACKS ARE EMPTY AND NOTHING CAN BE POPPED
    test4();
    
    
}

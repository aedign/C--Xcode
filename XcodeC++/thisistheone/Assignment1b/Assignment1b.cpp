//  Andres Di Gregorio
//  CS3305 Section 07
//  09/02/2019
//
//  Assignment1b.cpp
//  Assignment1b
//
//  Created by Andres Di Gregorio on 9/2/19.
//  Copyright © 2019 Andres Di Gregorio. All rights reserved.
//

#include <iostream>
#include "Assignment1b.h"

using namespace std;

    perfectNumber::perfectNumber(){
    
    }

// Precondition: The function takes an int value and analyzes wether this is a perfect number or not. If the input is not a valid integer, the program will stop and ask the user to do it again.
// Postcondition: The number will be analyzed by using "if" statements and a "for" loop, which will determine the result. The program will display the result as soon as it is determined.

    void perfectNumber::analyzeNumber(int num){
        
        number = num; // the input "num" is stored in the private int belonging to the object
        
        if (number <= 0){
            cout << "This is not a valid positive integer. Please try again" << endl;
        }
        
        else {
            
            this->remainder = 0; // this variable stores the remainder of the division between the input number and its divisors//
            this->sum = 0; // this variable stores the sum of all the numbers that, after being divided by the input number, yield a remainder of 0
            
            for (int divisor = number -1; divisor > 0; divisor--){
                
                remainder = number % divisor;
          
                if (remainder == 0){
                    
                    sum+= divisor; // the variable "sum" only takes the numbers that yield a remainder of 0
                    
                    if (sum == number){ // if the "sum" variable is already equal to the input number, then the function stops and a perfect number has been found
                        
                        cout << number << " is a perfect number" << endl;
                        break;
                    }
                    
                }
                
                if (divisor == 1){ // if the "divisor" variable is "1" and the previous "if" statements did not stop the loop, then a perfect number ha not been found and the functions reaches its end
                    
                    cout << number << " is not a perfect integer" << endl;
                    break;
                }
                
                
            }
            
        
            
        }
        
        
    }
    
    
    int main(){
        
        cout << "Please enter a positive integer:" << endl;
        
        int number;
        
        cin >> number;
        
        perfectNumber numberOne;
        
        numberOne.analyzeNumber(number);
    }
    
    

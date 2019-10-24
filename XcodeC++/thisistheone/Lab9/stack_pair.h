//
//  stack_pair.h
//  Lab9
//
//  Created by Andres Di Gregorio on 10/24/19.
//  Copyright © 2019 Andres Di Gregorio. All rights reserved.
//

#ifndef stack_pair_h
#define stack_pair_h

#include <stdio.h>
#include <cassert>
#include <iostream>
using namespace std;

template <class T>
class stack_pair {
public:
    static const int CAPACITY = 30;


    stack_pair(){
        
        top_a = 0;
        top_b = CAPACITY-1;
    }


    void push_a(T element){
        
        assert(!isFull_a());
        data[top_a] = element;
        top_a++;
    }

  
    void push_b(T element){
        
    assert(!isFull_b());
        data[top_b] = element;
        top_b--;
    }

  
    T pop_a(){
        
        assert(!isEmpty_a());
        top_a--;
        return data[top_a];
    }

    
    T pop_b(){
        
        assert(!isEmpty_b());
        top_b++;
        return data[top_b];
    }


    bool isEmpty_a() const{
        return (top_a == 0);
    }

    
    bool isEmpty_b() const{
        return (top_b == CAPACITY-1);
    }

    
    bool isFull_a() const{
    return (top_a > top_b);
    }

   
    bool isFull_b() const{
    return (top_b < top_a);
    }
    
    void print(){
        
        int i =0;
        
        while (i < CAPACITY){
            
            cout << data[i] << " ";
            i++;
        }
    }
    
private:
    
    T data[CAPACITY];
    size_t top_a;
    size_t top_b;


};


#endif /* stack_pair_h */



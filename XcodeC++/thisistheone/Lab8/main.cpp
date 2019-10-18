//
//  main2.cpp
//  Lab8
//
//  Created by Andres Di Gregorio on 10/17/19.
//  Copyright © 2019 Andres Di Gregorio. All rights reserved.
//

#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <set>
#include <algorithm>
#include "node2.h"
#include "bag5.h"

using namespace std;

int main(){
    
    bag<int> theBag;
    theBag.insert(3);
    theBag.insert(4);
    theBag.insert(2);
    theBag.insert(6);
    theBag.insert(7);
    theBag.insert(2);
    theBag.insert(2);
    theBag.insert(2);
    
    theBag.print_value_range(2, 8);
    cout << endl;
    theBag.remove_repetitions();
    theBag.print_value_range(2, 8);
    cout << endl;
    
    bag<string> theBag2;
    
    theBag2.insert("hello");
    theBag2.insert("hello");
    theBag2.insert("you");
    theBag2.insert("are");
    theBag2.insert("how");
    theBag2.insert("hello");
    theBag2.insert("how");
    theBag2.insert("hello");
    
    theBag2.print_value_range("hello", "a");
    cout << endl;
    theBag2.remove_repetitions();
    theBag2.print_value_range("hello","ar");
    cout << endl;
    theBag2.print_value_range("hello","are");
    
    
    cout << endl;
}

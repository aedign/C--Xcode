//
//  main.cpp
//  ExtraCredit
//  CS3305
//
//  Created by Andres Di Gregorio on 11/12/19.
//  Copyright © 2019 Andres Di Gregorio. All rights reserved.
//

#include <iostream>
#include "binary_Tree.hpp"

using namespace std;

int main(int argc, const char * argv[]) {

    binary_Tree bt1;

    bt1.create_first_node(1);
    cout << "Retrieve: " << bt1.retrieve() << endl;
    bt1.add_left(2);
    bt1.add_right(3);
    bt1.shift_left();
    cout << "Retrieve: " << bt1.retrieve() << endl;
    bt1.add_right(5);
    bt1.add_left(4);
    bt1.shift_right();
    cout << "Retrieve: " << bt1.retrieve() << endl;
    bt1.add_left(99);
    bt1.shift_left();
    bt1.add_right(100);
    bt1.change(11); // 99 changed to 11
    cout << "Retrieve: " << bt1.retrieve() << endl;
    bt1.shift_to_root();
    bt1.print();
    cout << endl;
    bt1.resize(50);
    bt1.shift_right();
    bt1.add_right(44);
    bt1.shift_right();
    bt1.add_right(55);
    bt1.shift_right();
    bt1.add_left(199);
    bt1.shift_left();
    bt1.change(200); // 199 changed to 200
    cout << "Retrieve: " << bt1.retrieve() << endl;
    bt1.print();
    
}

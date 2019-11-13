//
//  binaryTreeExtraCredit.cpp
//  ExtraCredit
//  CS3305
//  Created by Andres Di Gregorio on 11/12/19.
//  Copyright © 2019 Andres Di Gregorio. All rights reserved.
//

#include "binary_Tree.hpp"
#include <iostream>
using namespace std;

binary_Tree::binary_Tree( ){
    
    capacity = DEFAULT_CAPACITY;
    treeValues = new value_type[capacity];
    is_present = new bool[DEFAULT_CAPACITY]();
}

binary_Tree::~binary_Tree(){}

//Precondition: Size is equal to zero, which means the tree is empty
//Postcondition: A tree's first node is created, which increases the count by 1. This entry also makes the is_present array to be set to true at the same index
void binary_Tree::create_first_node(const value_type& entry){
    
    if(size() == 0){

        treeValues[0] = entry;
        count++;
        current_index = 0;
        is_present[0] = true;
    }
}

//Precondition: there is an existing tree
//Poscondition: the current node is moved to the root
void binary_Tree::shift_to_root( ){
    
    assert(size() > 0);
        current_index = 0;
}

//Precondition: the child has a parent
//Poscondition: the current node is moved up to the child's parent
void binary_Tree::shift_up( ){
    
    assert(has_parent() == true);
        current_index = (current_index-1)/2;
}

//Precondition: the parent has a left child
//Poscondition: the current node is moved down to the left child
void binary_Tree::shift_left( ){
    
    assert(has_left_child() == true);
        current_index = (2*current_index)+1;
}

//Precondition: the parent has a left child
//Poscondition: the current node is moved down to the right child
void binary_Tree::shift_right( ){
    
    assert(has_right_child() == true);
        current_index = (2*current_index)+2;
}


//Precondition: a tree exists
//Poscondition: the value of the node is changed to a new entered entry
void binary_Tree::change(const value_type& new_entry){
    
    assert(size() > 0);
        treeValues[current_index] = new_entry;
}

//Precondition: there is a tree and the current node does not have a left child
//Poscondition: a left child is added to the parent node. The is_present array's node at the same index is changed to "true"
void binary_Tree::add_left(const value_type& entry){
    
    assert(size() > 0 && has_left_child() == false);
        treeValues[(2*current_index)+1] = entry;
        is_present[(2*current_index)+1] = true;
        count++;
}

//Precondition: there is a tree and the current node does not have a right child
//Poscondition: a right child is added to the parent node. The is_present array's node at the same index is changed to "true"
void binary_Tree::add_right(const value_type& entry){
    
    assert(size() > 0 && has_right_child() == false);
        treeValues[(2*current_index)+2] = entry;
        is_present[(2*current_index)+2] = true;
        count++;
}

//Poscondition: returns the number of nodes in the tree
size_t binary_Tree::size( ) const{
    
    return count;
}

//Precondition: there is a tree to retrieve a value from
//Poscondition: the value of the current node is returned
binary_Tree::value_type binary_Tree::retrieve( ) const{
    
    assert(size() > 0);
        return treeValues[current_index];
}

//Precondition: there is a tree and the current node has a parent
//Poscondition: if the current node has a parent, it returns true. Otherwise, it returns false
bool binary_Tree::has_parent( ) const{
    
    if(size() > 0 && is_present[(current_index-1)/2] == true)
        return true;
    else
        return false;
}

//Precondition: there is a tree and the current node has a left child
//Poscondition: if the current node has a left child, it returns true. Otherwise, it returns false
bool binary_Tree::has_left_child( ) const{
    
    if(size() > 0 && is_present[(2*current_index)+1] == true)
        return true;
    else
        return false;
}

//Precondition: there is a tree and the current node has a right child
//Poscondition: if the current node has a right child, it returns true. Otherwise, it returns false
bool binary_Tree::has_right_child( ) const{
    
    if(size() > 0 && is_present[(2*current_index)+2] == true)
        return true;
    else
        return false;
}

//Poscondition: the entire tree is printed, including null values (represented by ".")
void binary_Tree::print(){
    
    cout << "Index" << "    " << "Values" << "    Current (index) at printing: " << current_index << endl;
    
    for(int i = 0; i < capacity; i++){
        if(is_present[i] == false)
            cout << i << "         " << "." << endl;
        else
            cout << i << "         " << treeValues[i] << endl;
    }
}

//Precondition: the newly entered capacity is greater than the current capacity
//Poscondition: the capacity of the tree has been increased
void binary_Tree::resize(size_type new_capacity){
    
    if(new_capacity == capacity)
        return;
    
    if (new_capacity > capacity){
    
        value_type* resizedTreeValues = new value_type[new_capacity];
    
        for (int i =0; i < capacity; i++)
            resizedTreeValues[i] = treeValues[i];
        
        delete [] treeValues;
        treeValues = resizedTreeValues;
        capacity = new_capacity;
    }
}


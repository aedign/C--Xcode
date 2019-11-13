//
//  binaryTreeExtraCredit.hpp
//  ExtraCredit
//  CS3305
//
//  Created by Andres Di Gregorio on 11/12/19.
//  Copyright © 2019 Andres Di Gregorio. All rights reserved.
//

#ifndef binary_Tree_hpp
#define binary_Tree_hpp
#include <cstdlib>  // Provides size_t
#include <stdio.h>
#include <cassert>

class binary_Tree{
    
    public:
    
    typedef int value_type;
    typedef std::size_t size_type;
    static const size_type DEFAULT_CAPACITY = 30;

    binary_Tree( );
    
    ~binary_Tree();

    void create_first_node(const value_type& entry);
    //Precondition: size( ) is zero.
    //stcondition: The tree now has one node (a root node), containing the specified entry. This new root node is the current node.
    void shift_to_root( );
    //Precondition: size( ) > 0.
    //Postcondition: The current node is now the root of the tree.
    void shift_up( );
    //Precondition: has_parent( ) returns true.
    //Postcondition: The current node has been shifted up to the parent of the old current node.
    void shift_left( );
    //Precondition: has_left_child( ) returns true.
    //Postcondition: The current node has been shifted down to the left child of the original current node.
    void shift_right( );
    //Postcondition: The current node has been shifted down to the right child of the original current node.
    void change(const value_type& new_entry);
    //Precondition: size( ) > 0.
    //Postcondition: The data at the current node has been changed to the new entry.
    void add_left(const value_type& entry);
    //Precondition: size( ) > 0, and has_left_child( ) returns false.
    //Postcondition: A left child has been added to the current node, with the given entry.
    void add_right(const value_type& entry);
    //Precondition: size( ) > 0, and has_right_child( ) returns false.
    //Postcondition: A right child has been added to the current node, with the given entry.
    size_t size( ) const;
    //Postcondition: The return value is the number of nodes in the tree.
    int retrieve( ) const;
    //Precondition: size( ) > 0.
    //Postcondition: The return value is the data from the current node.
    bool has_parent( ) const;
    //Postcondition: Returns true if size( ) > 0, and the current node has a parent.
    bool has_left_child( ) const;
    //Postcondition: Returns true if size( ) > 0, and the current node has a left child.
    bool has_right_child( ) const;
    //Postcondition: Returns true if size( ) > 0, and the current node has a right child.
    
    // THE FUNCTIONS BELOEW WERE ADDED BY ME. THEY WERE NOT PART OF THE GUIDELINE ON THE BOOK
    
    void print();
    // The entire array is printed. Empty values are displayed as "."
    void resize(size_type new_capacity);
    // It increments the size of the array by the new specified capacity

    private:
    
    size_type count; // numbers of entries in the array
    size_type current_index; 
    size_type capacity;
    value_type *treeValues; // array that contains the data entered in the tree
    bool *is_present; // array that specifies if an index is empty or not
};
#endif /* binary_Tree_hpp */

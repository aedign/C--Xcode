//
//  sequence2.cpp
//  Lab5
//
//  Created by Andres Di Gregorio on 9/19/19.
//  Copyright © 2019 Andres Di Gregorio. All rights reserved.
//

#include <cassert>
#include "sequence2.h"

using namespace main_savitch_4;

sequence::sequence(size_type initial_capacity){
    
    capacity = initial_capacity;
    data = new value_type[capacity];
    used = 0;
    
    current_index = 0;

    
}


sequence::sequence(const sequence& source){
    
     data = new value_type[source.capacity];
    
    for (int i =0; i < source.used; i++){
        data[i] = source.data[i];
    }
    
    used = source.used;
    capacity = source.capacity;
    current_index = source.current_index;
    
}


sequence::~sequence( ){
    
   
}


// MODIFICATION MEMBER FUNCTIONS
void sequence::resize(size_type new_capacity){
    
    if(new_capacity == capacity)
        return;
    
    if (new_capacity > used){
    
        value_type* data2 = new value_type[new_capacity];
    
        for (int i =0; i < used; i++){
        
            data2[i] = data[i];
        }
        delete [] data;
        data = data2;
        capacity = new_capacity;
        
    }
    
}


void sequence::start( ){
    
    if (used > 0){
        current_index = 0;
        
    }
    
}


void sequence::advance( ){
    
    if (is_item() == true){
        
        current_index++;
        
    }
    
    
}


void sequence::insert(const value_type& entry){
    
    if (is_item() == false){
        
        current_index = 0;
        
    }
    
 
        
        for (size_type i = used; i > current_index; i--){
            
            data[i] = data[i-1];
            
        }

        data[current_index] = entry;
        used++;
        
    
        
    }
    



void sequence::attach(const value_type& entry){
    
    if (is_item() == false){
        
        current_index = used-1;
        
    }
    
        for (size_type i = used-1; i > current_index; i--){
            
            data[i+1] = data[i];
 
        }
            current_index++;
            data[current_index] = entry;
            used++;

        
    }



void sequence::remove_current( ){
    
    if (is_item() == true){
        
        
        for (size_type i = current_index; i < used; i++){
            
            data[i] = data[i+1];
 
        }

        used--;
 
    }
    
    
}


void sequence::operator =(const sequence& source){
    
    if (this == &source)
        return;
    
    data = new value_type[source.capacity];
    
    for (int i =0; i < source.used; i++){
        data[i] = source.data[i];
    }
    
    used = source.used;
    capacity = source.capacity;
    current_index = source.current_index;
    
    
}


// CONSTANT MEMBER FUNCTIONS
sequence::size_type sequence::size( ) const{
    
    return used;
    
}


bool sequence::is_item( ) const{

    if (current_index < used){
        return true;
    }
    else{
        return false;
    }
    
    
}


sequence::value_type sequence::current( ) const{
    
    assert(is_item() == true);
        return data[current_index];
  

    
}





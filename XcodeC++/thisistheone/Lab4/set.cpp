//
//  set.cpp
//  Lab4
//
//  Created by Andres Di Gregorio on 9/12/19.
//  Copyright © 2019 Andres Di Gregorio. All rights reserved.
//


#include "set.h"


set::set(size_type initial_capacity){
    
    data = new value_type[initial_capacity];
    used = 0;
    capacity = initial_capacity;
    
}
// postcondition: empty set with initial_capacity having been created

set::~set(){
    
   
    
}
// postcondition: all dynamically allocated memory has been deallocated

set::set(const set& s){
    
    used = s.used;
    capacity = s.capacity;
    data = s.data;
    
}
// copy of s has been created;

void set:: operator= (const set& s){
    
    used = s.used;
    capacity = s.capacity;
    data = s.data;
   
    
}
// postcondition: exact copy of s has been assigned to the current set object

bool set::erase(const value_type& target){
    
    for(int i = 0; i < capacity; i++){
        
        if (data[i] == target){
            used--;
            data[i] = NULL;
            return true;
        }
    }
    
    return false;

}
// postcondition: returned true if target was removed from set or false if target was not in the set

bool set::insert(const value_type& entry){
    
    if (used == capacity){
        reserve(capacity+1);
        capacity = capacity+1;
    }
    
   if(contains(entry))
       return false;
    else
        data[used] = entry;
    used++;
    

    
    return true;
}
// postcondition: if entry was not in the set, then entry has been added - or nothing was done

void set::operator+= (const set& addend){
    
    for (int i = 0; i << addend.capacity; i++){
        
        value_type search = addend.data[i];
        bool check = false;
        
        for(int x = 0; x < capacity; x++){
            
            if (data[x] == search){
                check = true;
        
            }
            
        }
        
        if (check == false)
            capacity++;
        data[capacity-1] = search;
        used++;
        
    }
    
}
// postcondition: non-duplicating elements from addend have been added to the set

set::size_type set::size() const{
    
    return capacity;
    
}
// postcondition: number of elements in the set has been returned

bool set::contains(const value_type& target) const{
    
    for(int i =0; i < capacity; i++){
        
        if (data[i] == target){
            return true;
        }
    }
    
    return false;
}
// postcondition: returned whether target is in the set

std::ostream& operator<<(std::ostream& output, const set& s){
    
    for (int i = 0; i < s.used; i++){
        
        if (i==0){
            
            output << "{ ";
        }

        output << s.data[i];
        
        if (i >= 0 && i < s.used-1){
            
            output << ", ";
        }
        
        if (i == s.used-1){
            
            output << " }";
        }
        
        
    }
    
    return output;
   
    
}

void set::reserve (size_type new_capacity){
    
    value_type* data2 = new value_type[new_capacity];
    
    for (int i =0; i < used; i++){
        
        data2[i] = data[i];
    }
    
    data = data2;
    
    
}

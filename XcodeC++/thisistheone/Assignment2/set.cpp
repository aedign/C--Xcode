// Class: CS3305 Section 07
// Fall 2019
// Andres Di Gregorio
// 10/01/19.
// Instructor: Deepa Muralidhar
// Assignment 2

#include <iostream>
#include <stdio.h>
#include "set.h"

using namespace std;

set::set(size_type initial_capacity) // Big O Complexity: O(1)
{
    
    data = new value_type[initial_capacity];
    used = 0;
    capacity = initial_capacity;
    
}// postcondition: empty set has been created
    


  set::~set() // Big O Complexity: O(1)
{
  }// postcondition: set has been deallocated
    
  


  set::set (const set& source) // Big O Complexity: O(1)
{
      used = source.used;
      capacity = source.capacity;
      data = source.data;
    
  }// postcondition: a copy of source has been created
    


    //precondition: the set that will be copied is not equal to the new set receiving the copy
set& set::operator = (const set& source) // Big O Complexity: O(1)
{
    
    if (*this == source){
        return *this;
    }
    
    set newset;
    
    this->used = source.used;
    this->capacity = source.capacity;
    this->data = source.data;
        
    return *this;

}// postcondition: the set that has received the copy is returned
    


    //precondition: If the item is in the set, it is not added. If the entry is not in the set but the set has reached its max capacity, then the capacity is increased by 1 in order to alloacte the new entry.
  void set::insert (const value_type& entry)// Big O Complexity: O(n)
{
    if(contains(entry))
        return;
    else{
        if (used == capacity){
            resize(capacity+1);
            capacity = capacity+1;
        }
             data[used] = entry;
                used++;
    }
         
  }// postcondition: entry is in the set
    


    //precondition: if the set only has one value, the it is removed and "used" is set to 0.
  void set::remove (const value_type& entry)// Big O Complexity: O(n)
{
      
      if (used==1){
          data[used-1] = NULL;
          used--;
          return;
      }
      
      for(int i = 0; i < used; i++){
             
             if (data[i] == entry){
                 used--;
                 data[i] = data[used];
             }
         }
      
  }// postcondition: entry is not in the set
    

  set::size_type set::size() const // Big O Complexity: O(1)
{
      
      return used;
      
  }// postcondition: number of elements in the set has been returned
    

  bool set::contains (const value_type& entry) const // Big O Complexity: O(n)
{
      
      for(int i =0; i < used; i++){
             
             if (data[i] == entry){
                 return true;
             }
         }
         
         return false;
    
  }// postcondition: whether entry is in the set has been returned
    

set set_union (const set& s1, const set& s2) // Big O Complexity: O(n^2)
{
    
    set s3;
    s3 = s1;
    
    for(int i =0; i < s2.used; i++){
            
            s3.insert(s2.data[i]);
    }
  
    return s3;
    
}//postcondition: union of s1 & s2 has been returned
    

set set_intersection (const set& s1, const set& s2) // Big O Complexity: O(n^2)
{
    
    set s4;
    set::value_type *data3 = new set::value_type[s4.capacity];

    set::value_type temp;
    
    for(int i =0; i < s1.used; i ++){
        
        temp = s1.data[i];
        
        if(s1.contains(temp) && s2.contains(temp)){
            data3[s4.used] = temp;
            s4.used++;
        }
    }
    
    s4.data = data3;
    delete [] data3;
    return s4;
    
}// postcondition: intersection of s1 & s2 has been returned
    

set set_difference (const set& s1, const set& s2) // Big O Complexity: O(n^2)
{
    
    set s4;
    s4 = s1;

    for (int i = 0; i < s2.used; i++){

            s4.remove(s2.data[i]);
    }
    
    return s4;
    
}// postcondition: difference of s1 - s2 has been returned
    

bool is_subset (const set& s1, const set& s2) // Big O Complexity: O(n^2)
{
    
    for(int i = 0; i < s2.used; i++){
        
        if(!s2.contains(s1.data[i]))
            return false;
    }
    
    return true;
    
}// postcondition: returned whether s1 is a subset of s2
    


    //precondition: if the size and data of the sets are equal, it returns true. Otherwise, it returns false
bool operator == (const set& s1, const set& s2) // Big O Complexity: O(1)
{
    
    if(s1.size() == s2.size() && s1.data == s2.data){
        
        return true;
        
    }
       else {
           
        return false;
    }
       
    return false;
    
}// postcondition: returned whether s1 & s2 are equal
  

std::ostream& operator << (std::ostream& output, const set& s) // Big O Complexity: O(n)
{
    
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
    
    
}// postcondition: s has been displayed on output


set::size_type find (const set::value_type& entry) // Big O Complexity: O(1)
{
    
    //FUNCTION NOT USED. Necessary (?)
    
    return 1;
    
}// postcondition: returned location of entry in the set if entry is in the set - used otherwise


    //precondition: if the new size passed is equal to the current capacity, then it is not changed.
void set::resize (unsigned int new_size) // Big O Complexity: O(n)
{
    
    if(new_size == capacity){
        return;
    }
    
    value_type* data2 = new value_type[new_size];
    
    for (int i =0; i < used; i++){
        
        data2[i] = data[i];
    }
    
    data = data2;
    
}// postcondition: size of the array has been increased



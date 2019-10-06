//
//  sequence3.cpp
//  Lab6
//
//  Created by Andres Di Gregorio on 9/26/19.
//  Copyright © 2019 Andres Di Gregorio. All rights reserved.
//
#include <iostream>
#include <cassert>
#include <stdio.h>
#include "sequence3.h"


using namespace main_savitch_5;

sequence::sequence( ){
    
    head_ptr = NULL;
    tail_ptr= NULL;
    cursor= NULL;
    precursor= NULL;
    many_nodes = 0;
   
}

sequence::sequence(const sequence& source){
    
    list_copy(source.head_ptr, head_ptr, tail_ptr);
    many_nodes = source.many_nodes;
    
    if(source.precursor == NULL){
        
        precursor = NULL;
        cursor = head_ptr;
    }
    else{
        node *newnode;
        newnode = source.head_ptr;
        int index = 1;
        while(newnode != source.precursor){
            
            index++;
            newnode = newnode->link();
 
        }
        
        precursor = list_locate(head_ptr, index);
        cursor = precursor->link();
    }
    
    
    
}



sequence::~sequence( ){
    
    list_clear(head_ptr);
    many_nodes =0;
    
}



// MODIFICATION MEMBER FUNCTIONS
void sequence::start( ){
    
    precursor = NULL;
    cursor = head_ptr;
    
    std::cout << "START WORKS 00000"<< std::endl;
    
    if(head_ptr!=NULL){
        std::cout << "START HEAD" << cursor->data() << std::endl;
    }
   
}



void sequence::advance( ){
    
    if (is_item() == true){
        
            precursor = cursor;
            cursor = cursor->link();
        if(cursor!=NULL){
  //      std::cout << "ADVANCED "<< cursor->data()<< std::endl;
        }
          
        }
    
    
}



void sequence::insert(const value_type& entry){
    
    if(!is_item()){
    
    if (many_nodes==0){
        
        list_head_insert(head_ptr, entry);
        cursor = head_ptr;
        tail_ptr = head_ptr;
        std::cout << "cursor is head " << cursor->data() << std::endl;

    }
    else{
        std::cout << "INSERTED 2 " << std::endl;
        std::cout << head_ptr->data()<<std::endl;
        start();
        list_head_insert(head_ptr, entry);
        std::cout << head_ptr->data()<<std::endl;
        head_ptr->set_link(cursor);
        start();

    }
    }
    else{
        
        if(cursor==head_ptr){
            list_head_insert(head_ptr, entry);
            start();
        }
        else{
            std::cout << "head" << head_ptr->data() << std::endl;
            std::cout << "cursor" << cursor->data() << std::endl;
        std::cout << "whatever" << std::endl;
        list_insert(precursor, entry);
        std::cout << "cursor" << cursor->data() << std::endl;
            cursor = precursor->link();
 std::cout << "cursor" << cursor->data() << std::endl;
        }
    }
    
    many_nodes++;
   
}




void sequence::attach(const value_type& entry){
    
    if(!is_item()){
    
    if (many_nodes == 0){
        
        list_head_insert(head_ptr, entry);
        cursor = head_ptr;
        tail_ptr = head_ptr;
        std::cout << "attach head" <<std::endl;
    }

    else {
        std::cout << "ATTACH 2 " << std::endl;
        
        list_insert(tail_ptr, entry);
        tail_ptr = tail_ptr->link();
        advance();
        
        }
    }
    else{
    
        list_insert(cursor, entry);
        advance();
        
        if (tail_ptr == precursor){
            
            tail_ptr = cursor;
            std::cout << " PRECURSOR " << precursor->data() << std::endl;
            
        }
        
        
    
    }

//    std::cout << " CURSOR " << cursor->data() << std::endl;
//    std::cout << " HEAD " << head_ptr->data() << std::endl;
    
    many_nodes++;
    
}





void sequence::operator =(const sequence& source){
    
    if (this == &source){
        return;
    }
    
    if(size() > 0){
        
        list_clear(head_ptr);
        
    }

       list_copy(source.head_ptr, head_ptr, tail_ptr);
        many_nodes = source.many_nodes;
           
           if(source.precursor == NULL){
               
               precursor = NULL;
               cursor = head_ptr;
           }
           else{
               node *newnode;
               newnode = source.head_ptr;
               int index = 1;
               while(newnode != source.precursor){
                   
                   index++;
                   newnode = newnode->link();
        
               }
               
               precursor = list_locate(head_ptr, index);
               cursor = precursor->link();
           }
    
}




void sequence::remove_current( ){
    
    if(is_item()){
        
        if(precursor == NULL){
            std::cout << " HELLOOOOOOOOOOOOOOOO" << std::endl;
            cursor = cursor->link();
            list_head_remove(head_ptr);
            head_ptr = cursor;
        
        }
        
       
        else {
            
            if(cursor == tail_ptr){
                std::cout << "cursor==tail" << std::endl;
                list_remove(precursor);
                tail_ptr = precursor;
                cursor = precursor->link();
  
            }
            else{
                
            std::cout << "cursor before removing: " << cursor->data() << std::endl;
            cursor = cursor->link();
            list_remove(precursor);

            
            }
    
            
        }
        
                    many_nodes--;
        
    }
    
}



// CONSTANT MEMBER FUNCTIONS

sequence::size_type  sequence:: size( ) const{
    
    return many_nodes;
    
}




bool sequence::is_item( ) const {
 
    return (cursor != NULL);
    
    
}


sequence::value_type sequence::current( ) const{
    
    assert(is_item());
    return cursor->data();
    
}

//
//  main.cpp
//  Lab7B
//
//  Created by Andres Di Gregorio on 10/10/19.
//  Copyright © 2019 Andres Di Gregorio. All rights reserved.
//
#include <cstdlib>
#include <iostream>
#include "node1.h"
#include "check_lists.h"

using namespace std;
using namespace main_savitch_5;

void list_print(node*head_ptr){
    
    for(node* i = head_ptr; i != NULL; i = i->link()){

        cout << i->data() << " ";
        
        if(i->link() == NULL){
            cout << endl;
        }
    }
}


int main(int argc, const char * argv[]) {
   
    node* head_ptr = NULL;
    
    double nums[5] = {23.5, 45.6, 67.7, 89.8, 12.9};
    int size = sizeof(nums)/sizeof(nums[0]);
      
      for(int i =0; i < size; i++){
        
              list_head_insert(head_ptr, nums[i]);
      }
    
    list_print(head_ptr);
    
    check_list1(head_ptr);
    
    
    
    
    
    node* head_ptr2 = NULL;
    node* tail_ptr2 = NULL;
    
    double nums2[] = {23.5, 45.6, 67.7, -123.5, 89.8, 12.9};
    int size2 = sizeof(nums2) / sizeof(nums2[0]);

    for(int i = 0; i < size2; i++){
        if(i==0){
            list_head_insert(head_ptr2, nums2[i]);
        }
        else if (i==1){
            list_insert(head_ptr2, nums2[i]);
            tail_ptr2 = head_ptr2->link();
        }
        else{
            list_insert(tail_ptr2, nums2[i]);
            tail_ptr2 = tail_ptr2->link();
        }
    }

    list_print(head_ptr2);
    
    check_list2(head_ptr2);
    
    
    
    
    
    node* head_ptr3 = NULL;
    node* tail_ptr3 = NULL;
    
    list_copy(head_ptr, head_ptr3, tail_ptr3);
    
    list_print(head_ptr3);
    
    check_list1(head_ptr3);
    
    
    
    
    
    list_head_remove(head_ptr2);
    
    list_print(head_ptr2);
    
    check_list2B(head_ptr2);
    
    
    
    
    
    list_remove(list_locate(head_ptr2, 2));
    
    list_print(head_ptr2);
    
    check_list2C(head_ptr2);
    

    return 0;
}



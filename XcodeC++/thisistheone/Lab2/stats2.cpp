// Andres Di Gregorio
// 09/05/2019
// Data Structures Lab Section 08
//  Lab2

#include <iostream>
#include "stats2.h"

using namespace std;

statistician::statistician(){
    reset();
}

void statistician::next(double r){
    
    if (count == 0){
        
        tinyest = r;
        largest = r;

    }
    
   if (r < tinyest){
        tinyest = r;
    }
    
    if (r > largest){
        
        largest = r;
    }
    
    total += r;
    count++;
    
    
}

void statistician::reset(){
    
    count = 0;
    total = 0;
    tinyest = 0;
    largest = 0;
}

int statistician:: length( ) const{
    
    return count;
    
}

double statistician:: sum( ) const{
    
    return total;
    
}

double statistician::mean( ) const{
    
    
    return (total / count);
}


double statistician:: minimum( ) const{
    
    if (length() == 0){
        return 0;
    }
    else{
        return tinyest;
    }
}



double statistician:: maximum( ) const{
    
    if (length() == 0){
        return 0;
    }
    else {
        return largest;
    }
    
}

statistician operator + (const statistician& s1, const statistician& s2){
    
    statistician temp;
    
    if (s1.count == 0){
        
        return s2;
    }
    
    else if (s2.count == 0){
        
        return s1;
    }
  
    temp.count = s1.count + s2.count;
    temp.total = s1.total + s2.total;
    
    if (s1.tinyest < s2.tinyest){
        
        temp.tinyest = s1.tinyest;
    }
    else {
        temp.tinyest = s2.tinyest;
    }
    
    if (s1.largest < s2.largest){
        temp.largest = s2.largest;
    }
    else {
        temp.largest = s1.largest;
    }
    
    return temp;
    
}

statistician operator * (double scale, const statistician& s){
    
    statistician temp;
    

    if(s.count == 0){
        return s;
    }
    
    else {
        
    temp.count = s.count;
    temp.total = s.total * scale;
    temp.largest = s.largest * scale;
    temp.tinyest = s.tinyest * scale;

    }
    

    if (scale <= 0){
       
        double copy;
        
        copy = temp.largest;
        temp.largest = temp.tinyest;
        temp.tinyest = copy;
        
    }
    
    return temp;
    
}

bool operator == (const statistician& s1, const statistician& s2){
    
    
    if (s1.length() == 0 && s2.length() == 0){
        return true;
    }
    
   else if (s1.length() != s2.length()){
        
        return false;
        
   }

      else if (s1.sum() != s2.sum()){
                
                return false;
           
            }
           
               else if (s1.mean() != s2.mean()){
               
                    return false;
               
                }
           
                   else if (s1.minimum() != s2.minimum()){
                        
                        return false;
               
                    }
           
                       else if(s1.maximum() != s2.maximum()){
                            
                            return false;
               
               
                        }
       
    return true;
    
}



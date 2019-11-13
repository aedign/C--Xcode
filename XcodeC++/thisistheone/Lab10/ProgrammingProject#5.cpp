//
//  recursiveFunction5.cpp
//  Lab10
//
//  Created by Andres Di Gregorio on 10/31/19.
//  Copyright © 2019 Andres Di Gregorio. All rights reserved.
//

#include "ProgrammingProject#5.hpp"

double recursiveFunction5(unsigned int n){
    
    if(n == 1)
        return 1.0;
    else {
        return (1.0/n) + recursiveFunction5(n-1.0);
    }
    
}

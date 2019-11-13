//
//  ProgrammingProject#1.cpp
//  Lab10
//
//  Created by Andres Di Gregorio on 10/31/19.
//  Copyright © 2019 Andres Di Gregorio. All rights reserved.
//

#include "ProgrammingProject#1.hpp"

void recursiveFunction1(unsigned int levels,unsigned int start ){
    
    if(levels < 1)
        return;
    else{
        for(int i =1 ; i < start; i++)
            cout << " ";
        cout << "This was written by call number " << start << endl;
        recursiveFunction1(levels-1,start+1);
        for(int i =1 ; i < start; i++)
        cout << " ";
        
        cout << "This was ALSO written by call number " << start << endl;
        
    }
    
}



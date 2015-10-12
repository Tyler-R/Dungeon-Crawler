//
//  main.cpp
//  Authentication
//
//  Created by Arsalan Nr on 2015-10-02.
//  Copyright (c) 2015 Arsalan Nr. All rights reserved.
//

#include <iostream>
#include "Authentication.h"

#include <string>

int main(int argc, const char * argv[]) {
    
    
    Authentication a("Arsalan","236320");
        if (a.login()){
            std::cout<<"The user exist"<<std::endl;
        }
    
    
//    Authentication b("Khashayar","23630asd");
//    b.signUp();
    
    
//    Authentication a("Ali", "Jaghi");
//    if (a.login()){
//        std::cout<<"The user exist"<<std::endl;
//    }
//    
//    std::cout<<"Arsalan Noroozzadeh"<<std::endl;
    return 0;
    
}


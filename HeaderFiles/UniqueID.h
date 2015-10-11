#ifndef __Authentication__UserID__
#define __Authentication__UserID__

#include <iostream>
#include "UserSignUp.h"

class UniqueID {
    
private:
    int ID;
    
protected:
    static int nextID;
    int test;
    
public:
    UniqueID();
    UniqueID(const UniqueID& orig);
    UniqueID& operator=(const UniqueID& orig);
    int getUniqueID();
};

#endif
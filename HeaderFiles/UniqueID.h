#include <iostream>

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


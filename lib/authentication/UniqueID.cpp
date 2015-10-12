#include "UniqueID.h"

int UniqueID::nextID = 0;

UniqueID::UniqueID() {

    ID = ++nextID;
    test = 0;

}

UniqueID::UniqueID(const UniqueID& orig) {
    
    ID = orig.ID;
}

UniqueID& UniqueID::operator=(const UniqueID& orig) {
    
    ID = orig.ID;
    return(*this);
}

int UniqueID::getUniqueID(){
    
    return ID;
}

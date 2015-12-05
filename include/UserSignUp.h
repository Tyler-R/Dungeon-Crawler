
#ifndef Authentication_UserSignUp_h
#define Authentication_UserSignUp_h

#include <string>
#include "UniqueID.h"
#include "FileIO.h"

class UserSignUp {
    
private:
    int userID;
    std::string userName;
    std::string userPassword;
    
    
public:
    UserSignUp(std::string userName, std::string userPassword);
    std::string getUserName();
    std::string getUserPassword();
    void generateUserID();
    int getUserID();
    bool IsUserSignedUp();
    bool isUserActivce();
    

};

#endif
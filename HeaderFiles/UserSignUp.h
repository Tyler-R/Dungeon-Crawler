#include <string>
#include "UniqueID.h"

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
    bool userIsLoggedIn();
    bool isUserActivce();
    
    
};


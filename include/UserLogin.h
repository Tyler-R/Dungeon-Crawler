#ifndef __Authentication__UserLogin__
#define __Authentication__UserLogin__

#include <stdio.h>
#include <string>

class UserLogin {
    
private:
    std::string userName;
    std::string userPassword;
    
public:
    UserLogin(std::string userName, std::string userPassword);
    bool isUserLoggedIn();
};


#endif
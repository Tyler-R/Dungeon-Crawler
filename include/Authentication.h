#ifndef __Authentication__Authentication__
#define __Authentication__Authentication__

#include <stdio.h>
#include <string>
#include "UserLogin.h"
#include "UserSignUp.h"
//#include "UserLogout.h"

class Authentication {
    std::string userName;
    std::string userPassword;
    
public:
    Authentication(std::string userName, std::string userPassword);
    bool login();
    bool logout();
    bool signUp();
    
};

#endif
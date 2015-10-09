#include <stdio.h>
#include <string>


class UserLogin {
    std::string userName;
    std::string userPassword;
    
public:
    UserLogin(std::string userName, std::string userPassword);
    bool isUserLoggedIn();
};

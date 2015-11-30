#include "UserLogin.h"
#include "FileIO.h"


UserLogin::UserLogin(std::string userName, std::string userPassword){
    
    this->userName = userName;
    this->userPassword = userPassword;
    
}

bool UserLogin::isUserLoggedIn(){
    
    FileIO fileLogin(userName,userPassword);
    return fileLogin.recordExist();
    
}
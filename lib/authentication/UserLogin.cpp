#include "UserLogin.h"
#include "FileIO.h"


UserLogin::UserLogin(std::string userName, std::string userPassword){
    
    this->userName = userName;
    this->userPassword = userPassword;
    
}

bool UserLogin::isUserLoggedIn(){
    
    FileIO fileLogin(userName,userPassword);
    fileLogin.openFileConnectionToRead();
    if (fileLogin.readFromFile()){
        
        fileLogin.closeReadFileConnection();
        return true;
    }
    fileLogin.closeReadFileConnection();
    return false;
    
}
#include "Authentication.h"

Authentication::Authentication(std::string userName, std::string userPassword){
    
    this-> userName = userName;
    this-> userPassword = userPassword;
    
}
bool Authentication::login(){
    
    UserLogin fileLogin(userName, userPassword);
    if (fileLogin.isUserLoggedIn()){
        return true;
    }
    return false;
}

bool Authentication::logout(){
   
    return false;
}


bool Authentication::signUp(){
    
    UserSignUp fileSignUp(userName,userPassword);
    
    if (fileSignUp.IsUserSignedUp()){
        return true;
    }
    return false;
    
}
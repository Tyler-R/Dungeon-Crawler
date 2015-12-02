#include "Authentication.h"

Authentication::Authentication(std::string userName, std::string userPassword){
    
    this-> userName = userName;
    this-> userPassword = userPassword;
    
}
bool Authentication::login(){
    
    UserLogin fileLogin(userName, userPassword);
    return fileLogin.isUserLoggedIn();
}

// bool Authentication::logout(){
    
//     UserLogout fileLogOut(userName,userPassword);
//     return fileLogOut.isUserLoggedOut();
// }


bool Authentication::signUp(){
    
    UserSignUp fileSignUp(userName,userPassword);
    return fileSignUp.IsUserSignedUp();
    
}
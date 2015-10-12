#include "UserSignUp.h"

UserSignUp::UserSignUp(std::string userName, std::string userPassword ){
    
    this->userName = userName;
    this->userPassword = userPassword;
    generateUserID();
}

std::string UserSignUp::getUserName(){
    
    return userName;
}


std::string UserSignUp::getUserPassword(){
    
    return userPassword;
}


void UserSignUp::generateUserID(){
    
    UniqueID ID;
    this-> userID = ID.getUniqueID();
}


int UserSignUp::getUserID(){
    
    return userID;
}

bool UserSignUp::IsUserSignedUp(){
    
    FileIO fileSignUp(userName, userPassword, userID);
    fileSignUp.openFileConnectionToWrite();
    if (fileSignUp.writeToFile()){
        
        fileSignUp.closeWriteFileConnection();
        return true;
    }
    fileSignUp.closeWriteFileConnection();
    return false;
}




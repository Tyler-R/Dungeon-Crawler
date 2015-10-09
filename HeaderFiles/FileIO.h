#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include "UserSignUp.h"

class FileIO {

private:
    int userID;
    bool isUserActive;
    std::string userName;
    std::string userPassword;
    std::ofstream outFile;
    
    // This is the path to store user records
    const std::string USER_RECORDS = "/Users/Arsalan/Desktop/records.txt";
    
public:
    FileIO(UserSignUp userInfo);
    FileIO();
    void openFileConnectionToWrite();
    void writeToFile();
    void closeWriteFileConnection();
    void openFileConnectionToRead();
    void ReadFromFile();
    void closeReadFileConnection();
    bool isUserLoggedIn();
    void readFromFile();
    
};

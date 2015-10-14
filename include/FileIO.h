#ifndef __Authentication__FileIO__
#define __Authentication__FileIO__

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include "UserSignUp.h"
#include <sstream>
#include <vector>
#include <iterator>

class FileIO {

private:
    int userID;
    bool isUserActive;
    std::string userName;
    std::string userPassword;
    std::ofstream outFile;
    std::ifstream inFile;
    const std::string USER_RECORDS = "/home/textadventure/docs/records.txt";
    bool recordExist();
    
public:
    FileIO(std::string userName, std::string userPassword, int userID);
    FileIO(std::string userName, std::string userPassword);
    void openFileConnectionToWrite();
    bool writeToFile();
    void closeWriteFileConnection();
    void openFileConnectionToRead();
    bool readFromFile();
    void closeReadFileConnection();
    bool isUserLoggedIn();
    
};

#endif

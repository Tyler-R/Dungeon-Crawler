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
    const std::string USER_RECORDS = "records.txt";
    const int USER_NAME_FIELD = 1;
    const int USER_PASS_FIELD = 2;
    void openFileConnectionToWrite();
    void closeWriteFileConnection();
    void openFileConnectionToRead();
    void closeReadFileConnection();
    
public:
    FileIO(std::string userName, std::string userPassword, int userID);
    FileIO(std::string userName, std::string userPassword);
    bool writeToFile();
    bool recordExist();
    
};

#endif
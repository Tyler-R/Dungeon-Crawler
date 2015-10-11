#include "FileIO.h"


FileIO::FileIO(std::string userName, std::string userPassword, int userID){
    
    this->userName = userName;
    this->userPassword = userPassword;
    this->userID = userID;
    
}

FileIO::FileIO(std::string userName, std::string userPassword){
    
    std::cout<< "I reached here"<<std::endl;
    this-> userName = userName;
    this-> userPassword = userPassword;
    
}

void FileIO::openFileConnectionToWrite(){
    
    outFile.open(USER_RECORDS, std::ios_base::app);
    
}

bool FileIO::writeToFile(){
    
    outFile << userID << " " ;
    outFile << userName << " ";
    outFile << userPassword << " ";
    outFile << std::endl;
    return true;
    
}

void FileIO::closeWriteFileConnection(){
    
    outFile.close();
}

bool FileIO::isUserLoggedIn(){
    
    return false;
}

bool FileIO::readFromFile(){
    
    std::string record;
     while(getline(inFile, record)) {
        if (record.find(userName, 0) != std::string::npos && record.find(userPassword, 0) != std::string::npos) {
            std::cout << "found: " << userName <<" and "<< userPassword << "line: " << std::endl;
            return true;
        }
    }
    return false;
}

void FileIO::openFileConnectionToRead(){
    
    inFile.open(USER_RECORDS);
}

void FileIO::closeReadFileConnection(){
    
    inFile.close();
}





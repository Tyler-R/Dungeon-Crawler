#include "FileIO.h"


FileIO::FileIO(std::string userName, std::string userPassword, int userID){
    
    this->userName = userName;
    this->userPassword = userPassword;
    this->userID = userID;
    
}

FileIO::FileIO(std::string userName, std::string userPassword){
    
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
    std::vector<std::string> vec;
    
    while(getline(inFile, record)) {
        
        vec.push_back(record);
        
    }
    for (int i = 0; i < vec.size();i++){
        std::istringstream buf(vec[i]);
        std::istream_iterator<std::string> beg(buf), end;
        std::vector<std::string> tokens(beg, end);
        if (tokens[1] == userName && tokens[2] == userPassword){
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





#include "FileIO.h"


FileIO::FileIO(std::string userName, std::string userPassword, int userID){
    
    this->userName = userName;
    this->userPassword = userPassword;
    this->userID = userID;
    isUserActive = false;
    
}

FileIO::FileIO(std::string userName, std::string userPassword){
    
    this-> userName = userName;
    this-> userPassword = userPassword;
    
}

void FileIO::openFileConnectionToWrite(){
    
    outFile.open(USER_RECORDS, std::ios_base::app);
    
}

bool FileIO::writeToFile(){
    
    bool userFound = recordExist();
    openFileConnectionToWrite();
    if(userFound == true){
        closeWriteFileConnection();
        return false;
    }else{
        outFile << userID << " " ;
        outFile << userName << " ";
        outFile << userPassword << " ";
        outFile << isUserActive << " ";
        outFile << std::endl;
        closeWriteFileConnection();
        return true;
    }
    
}

bool FileIO::recordExist(){
    
    openFileConnectionToRead();
    std::string record;
    std::vector<std::string> vec;
    
    // Store each record in the vector
    while(getline(inFile, record)) {
        
        vec.push_back(record);
        
    }
    // Tokenize each record
    for (int i = 0; i < vec.size();i++){
        std::istringstream buf(vec[i]);
        std::istream_iterator<std::string> beg(buf), end;
        std::vector<std::string> tokens(beg, end);
        if (tokens[USER_NAME_FIELD] == userName && tokens[USER_PASS_FIELD] == userPassword){
            closeReadFileConnection();
            return true;
        }
        
    }
    
    closeReadFileConnection();
    return false;
}



void FileIO::closeWriteFileConnection(){
    
    outFile.close();
}


void FileIO::openFileConnectionToRead(){
    
    inFile.open(USER_RECORDS);
}

void FileIO::closeReadFileConnection(){
    
    inFile.close();
}

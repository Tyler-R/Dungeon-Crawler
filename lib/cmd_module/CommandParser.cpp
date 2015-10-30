#include <fstream>
#include "CommandParser.h"
using namespace std;
/*
Command_Parser::Command_Parser(){

}
*/

string CommandParser::validateLookArgv(vector<string> &cmd){
    reformatTokens(cmd);
    return "look at" + cmd.at(1);
}
string CommandParser::validateMoveArgv(vector<string> &cmd){
    reformatTokens(cmd);
    return"go to" +cmd.at(1);
}

void CommandParser::reformatTokens(vector<string>& words){
    if (words.size() == 2) return;
    else{
        string tmp = "";
        while (words.size() != 1){
            tmp = words.back() +" "+ tmp;
            words.pop_back();
        }
        while(tmp.back() == ' '){
            tmp.pop_back();
        }

        words.push_back(tmp);
    }
}
vector<string> CommandParser::tokenizeInput(string &in){
    //suggested to change to deque
    //use std::copy
    //std::copy(tokens.begin(), tokens.end(), std::back_inserter(usr_input.begin()));
    //even better
    //std::deque<std::string> usr_input(tokens.begin(), tokens.end());
  vector<string> usr_input;
    typedef boost::tokenizer<boost::char_separator<char> > tokenizer;
    boost:: char_separator<char> delm(" ");
    tokenizer tokens(in, delm);
    for (auto &tokenWord: tokens){
        usr_input.push_back(tokenWord);
    }
    return usr_input;
}
void CommandParser::toLowerCase(string &str){
    const int length = str.length();
    for(int i=0; i < length; ++i)
    {
        str[i] = tolower(str[i]);
    }
}

bool CommandParser::isMoveCmd(vector<string> &words){
   fstream fs;
   bool matchFound = false;
   fs.open ("../../yaml/command/move.txt");
   string cmd;
   while(fs >> cmd){
    if(words.front().compare(cmd) == 0){
        matchFound = true;
    }
   }
   return matchFound;
}

bool CommandParser::isLookCmd(vector<string> &words){
    fstream fs;
    bool matchFound = false;
    fs.open("../../yaml/command/look.txt");
    string cmd;
    while(fs >> cmd){
    if(words.front().compare(cmd) ==0){
        matchFound = true;
        }
    }
    return matchFound;
}

// string CommandParser::invokeCommand(vector<string> cmd){

// }

/*entry point for the cmd_module api*/
string CommandParser::processCommand(string &in){
    if(in.empty()){
        return "invalid command: [empty]";
    }
   toLowerCase(in);
   vector<string> words = tokenizeInput(in);
   // YAML::Node config = YAML::Load("./Commands.yaml");

   // cout<<"processing..."<<words.front()<<endl;
   if(isMoveCmd(words)){
        // cout<<words.front();
        return validateMoveArgv(words);
   }
   else if(words.front().compare("kill") == 0){

        return  words.front();
   }
   else if(isLookCmd(words)){

        return validateLookArgv(words);
   }
   else {
    return "invalid command";
   }

}

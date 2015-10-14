#include "CommandParser.h"
using namespace std;
/*
Command_Parser::Command_Parser(){

}
*/
CommandParser::CommandParser(World& world){
  newWorld = world;
}
string CommandParser::validateLookArgv(vector<string> &cmd){
    /*call a function that returns a list of
    objects that can be look at; then iterate through to
    check whether input has a match */
    /*same goes to same kind of commands that require a lookup
    to the players current postion and objects*/
    if(cmd.at(1).compare("north") ==0){
      return newWorld.getCurrentRoom()->lookNorth();
    }
    else if (cmd.at(1).compare("south") ==0){
      return newWorld.getCurrentRoom()->lookSouth();
    }
    else if (cmd.at(1).compare("west") ==0){
      return newWorld.getCurrentRoom()->lookWest();
    }
    else if (cmd.at(1).compare("east") ==0){
      return newWorld.getCurrentRoom()->lookEast();
    }
    else if (cmd.at(1).compare("up") == 0){
      return newWorld.getCurrentRoom()->lookUp();
    }
    else if (cmd.at(1).compare("down") ==0){
      return newWorld.getCurrentRoom()->lookDown();
    }
    else if (cmd.at(1).compare("around") ==0){
      return newWorld.getCurrentRoom()->lookAround();
    }
    else{
      return newWorld.getCurrentRoom()->getObjDesc(cmd.at(1));
    }
}
string CommandParser::validateMoveArgv(vector<string> &cmd){
    if(cmd.at(1).compare("north") == 0){
        return newWorld.getCurrentRoom()->goNorth(newWorld.getCurrentRoom());
    }
    else if (cmd.at(1).compare("south") == 0 ){
        return newWorld.getCurrentRoom()->goSouth(newWorld.getCurrentRoom());
    }
    else if (cmd.at(1).compare("east") == 0){
        return newWorld.getCurrentRoom()->goEast(newWorld.getCurrentRoom());
    }
    else if (cmd.at(1).compare("west") == 0){
        return newWorld.getCurrentRoom()->goWest(newWorld.getCurrentRoom());
    }
    else if (cmd.at(1).compare("up") ==0){
        return newWorld.getCurrentRoom()->goUp(newWorld.getCurrentRoom());
    }
    else if (cmd.at(1).compare("down")==0){
        return newWorld.getCurrentRoom()->goDown(newWorld.getCurrentRoom());
    }
    else {
        return "\"" +cmd.at(1)+"\"" + " is not a valid input";
    }
}

void CommandParser::reformatTokens(vector<string>& words){
    if (words.size() == 2) return;
    else{
        string tmp = "";
        while (words.size() != 1){
            tmp = words.back() +" "+ tmp;
            words.pop_back();
        }
    if(tmp.back() == ' '){
        tmp.pop_back();
    }
    words.push_back(tmp);
    }
}
vector<string> CommandParser::tokenizeInput(string &in){
  vector<string> usr_input;
    typedef boost::tokenizer<boost::char_separator<char> > tokenizer;
    boost:: char_separator<char> delm(" ");
    tokenizer tokens(in, delm);
    for(tokenizer::iterator token_itr = tokens.begin();
     token_itr != tokens.end(); ++token_itr){
        usr_input.push_back(*token_itr);
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


// string CommandParser::invokeCommand(vector<string> cmd){

// }

/*entry point for the cmd_module api*/
string CommandParser::processCommand(string &in){
   toLowerCase(in);
   vector<string> words = tokenizeInput(in);
   reformatTokens(words);
   // cout<<"processing..."<<words.front()<<endl;
   if((words.front().compare("move") == 0)){
        // cout<<words.front();
        return validateMoveArgv(words);
   }
   /*
   else if(words.front().compare("kill") == 0){

        return  words.front();
   }
   */
   else if(words.front().compare("look") == 0){
        return validateLookArgv(words);
   }
   else {
    return "invalid command";
   }

}

#include <fstream>
#include "CommandParser.h"

using namespace std;
string CommandParser::validateLookArgv(vector<string> &cmd){
    reformatTokens(cmd);
    return "look at" + cmd.at(1);
}
string CommandParser::validateMoveArgv(vector<string> &cmd){
    reformatTokens(cmd);
    return"go to" +cmd.at(1);
}
string CommandParser::validaeAttackNPCArgv(vector<string> &cmd){
  reformatTokens(cmd);
  return "attack NPC" + cmd.at(1);
}

void CommandParser::reformatTokens(vector<string>& words){
    if (words.size() == 2) return;
    else{
        string tmp = "";
        while (words.size() != 1){
            tmp = words.back() +" "+ tmp;
            words.pop_back();
        }
        while(tmp.back() == ' ' || tmp.back()=='\t'){
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

vector<string> CommandParser::getGlobalCmdAlias(string generic_cmd){
  fstream fs;
  vector<string> cmd_alias;
  string cmd;
  // string prefix_dir = "textadventure/yaml/command/";
  string prefix_dir = "./command/";
  string filetype = ".txt";
  string cmd_file_path = prefix_dir + generic_cmd + filetype;
  cout<<cmd_file_path<<endl;
  fs.open(cmd_file_path);
  if(!fs.is_open()){
    cout<<"fail to open the file " << generic_cmd << endl;
  }
  while (fs >> cmd){
    cout<<cmd<<endl;
    cmd_alias.push_back(cmd);
  }
  fs.close();
  return cmd_alias;
}

bool CommandParser::findMatch(vector<string> &alias, string &word){
  bool matchFound = false;
  for (auto &cmd: alias){
      if(word.compare(cmd) ==0){
        matchFound = true;
      }
    }
  return matchFound;
}

bool CommandParser::isMoveCmd(vector<string> &words){
   vector<string> cmd_alias = getGlobalCmdAlias("move");
   return findMatch(cmd_alias, words.front());
}

bool CommandParser::isLookCmd(vector<string> &words){
    vector<string> cmd_alias = getGlobalCmdAlias("look");
    return findMatch(cmd_alias, words.front());
}



bool CommandParser::isAttackNPCsCmd(vector<string> &words){
  vector<string> cmd_alias = getGlobalCmdAlias("attackNPC");
  return findMatch(cmd_alias, words.front());
}
bool CommandParser::isAliasCmdGlobal(vector<string>& words){

}


/*entry point for the cmd_module api*/
string CommandParser::processCommand(string &in){
    if(in.empty()){
        return "invalid command: [empty]";
    }
   toLowerCase(in);
   vector<string> words = tokenizeInput(in);
   if(isMoveCmd(words)){
        return validateMoveArgv(words);
   }
   else if(isAttackNPCsCmd(words)){
        return  validaeAttackNPCArgv(words);
   }
   else if(isLookCmd(words)){
        return validateLookArgv(words);
   }
   else {
    return "invalid command";
   }

}

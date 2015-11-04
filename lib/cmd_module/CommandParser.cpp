#include <fstream>
#include "CommandParser.h"
using namespace std;

CommandParser::CommandParser(){

}

CommandParser::CommandParser(shared_ptr<User> user){
  PlayerOne = user;
}

string CommandParser::validateLookArgv(vector<string> &cmd){

    if(cmd.size() > 1){
      reformatTokens(cmd);
      if(cmd.at(1).compare("around") == 0){
        return PlayerOne->lookAround();
        // return "look around\n";
      }
      else if(cmd.at(1).compare("exit") == 0){
        // return"look at exit\n";
        return PlayerOne->lookExits();
      }
      else if(cmd.at(1).compare("inventory") == 0){
        // return "look at inventory\n";
       return  PlayerOne->viewInventory();
      }
      // return "look at " + cmd.at(1) + "\n";
      string first = PlayerOne->lookAt(cmd.at(1));
      string second = PlayerOne->lookObjKeywords(cmd.at(1));
      return  first + second;
    }
    else {
      // return "look at the current room\n";
      return PlayerOne->getRoom()->getDesc();
    }
}

string CommandParser::validateMoveArgv(vector<string> &cmd){

    if(cmd.size() == 1){
      if(cmd.front().compare("north") == 0){
        // return "move to north\n";
        return PlayerOne->moveTo("north");
      }
      else if(cmd.front().compare("south") == 0){
        // return "move to south\n";
        return PlayerOne->moveTo("south");
      }
      else if(cmd.front().compare("east") == 0){
        // return "move to east\n";
        return PlayerOne->moveTo("east");
      }
      else if(cmd.front().compare("west") == 0 ){
        // return "move to west\n";
        return PlayerOne->moveTo("west");
      }
      else {
        return "Usage: <move> <destination>\n";
      }
    }
    else{
      reformatTokens(cmd);
      // return"go to " +cmd.at(1) + "\n";
      return PlayerOne->moveTo(cmd.at(1));
    }
}

string CommandParser::validateAttackNPCArgv(vector<string> &cmd){
  if(cmd.size()==1){
      return "Usage: <attack> <NPC's name>\n";
   }
  else{
    reformatTokens(cmd);
    // return "attack NPC" + cmd.at(1) + "\n";
    return PlayerOne->attackNPC(cmd.at(1));
  }
}

string CommandParser::validateTakeArgv(std::vector<std::string>& cmd){
  if(cmd.size()==1){
    return "Usage: <take> <item's name>\n";
   }
  else{
    reformatTokens(cmd);
    // return "take " + cmd.at(1) + "\n";
    return PlayerOne->takeItem(cmd.at(1));
  }
}

string CommandParser::validateUsdeArgv(std::vector<std::string>& cmd){
  if(cmd.size()==1){
    return "Usage: <use> <item's name>\n";
   }
  else{
    reformatTokens(cmd);
    // return "use " + cmd.at(1) + "\n";
    return PlayerOne->useItem(cmd.at(1));
  }
}

string CommandParser::validateCheckArgv(std::vector<std::string>& cmd){
  if(cmd.size() == 1){
    // return "check inventory\n";
    return PlayerOne->viewInventory();
  }
  else {
    reformatTokens(cmd);
    return PlayerOne->getInvItemLongDesc(cmd.at(1));
    // return
  }
}

string CommandParser::validateTossArgv(std::vector<std::string>& cmd){
  if(cmd.size() == 1){
      return "Usage: <toss> <item name>\n";
  }
  else{
     reformatTokens(cmd);
     return PlayerOne->tossItem(cmd.at(1));
  }
}
string CommandParser::validateHelpArgv(std::vector<std::string>& cmd){
    return "USE: move, look, check, toss, take\n";
}
string CommandParser::validateAliasArgv(std::vector<std::string> &cmd){
  if(cmd.size() == 3){
    //user defined

  }
  else if(cmd.size() == 4){
    //global alias
  }
  else{
    return "Usage: <alias> <generic_cmd> <custom alias command>\n";
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
        while((tmp.back() == ' ') || (tmp.back()=='\t')){
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
  string prefix_dir = "command/";
  string filetype = ".txt";
  string cmd_file_path = prefix_dir + generic_cmd + filetype;

  fs.open(cmd_file_path);
  if(!fs.is_open()){
    cout<<"fail to open the file " << generic_cmd << endl;
  }
  while (fs >> cmd){
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

bool CommandParser::isTakeCmd(std::vector<std::string>& words){
  vector<string> cmd_alias = getGlobalCmdAlias("take");
  return findMatch(cmd_alias, words.front());
}

bool CommandParser::isCheckCmd(std::vector<std::string>& words){
  vector<string> cmd_alias = getGlobalCmdAlias("check");
  return findMatch(cmd_alias, words.front());
}

bool CommandParser::isUseCmd(std::vector<std::string>& words){
  vector<string> cmd_alias = getGlobalCmdAlias("use");
  return findMatch(cmd_alias, words.front());
}

bool CommandParser::isAliasCmd(std::vector<std::string>& words){
  return words.front().compare("alias") == 0;
}

bool CommandParser::isTossCmd(std::vector<std::string>& words){
  vector<string> cmd_alias = getGlobalCmdAlias("use");
  return findMatch(cmd_alias, words.front());
}

bool CommandParser::isHelpCmd(std::vector<std::string> &words){
  return words.front().compare("help") ==0;
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
      return validateAttackNPCArgv(words);
   }
   else if(isLookCmd(words)){
      return validateLookArgv(words);
   }
   else if(isUseCmd(words)){
      return validateUsdeArgv(words);
   }
   else if(isTakeCmd(words)){
      return validateTakeArgv(words);
   }
   else if(isCheckCmd(words)){
      return validateCheckArgv(words);
   }
   else if(isAliasCmd(words)){
      return validateAliasArgv(words);
   }
   else if(isTossCmd(words)){
      return validateTossArgv(words);
   }
   else if(isHelpCmd(words)){
    return validateHelpArgv(words);
   }
   else {
    return "invalid command";
   }

}

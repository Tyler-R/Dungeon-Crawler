#pragma once
#include <string>
#include <vector>
#include <boost/tokenizer.hpp>

using namespace std;

/*include "player.h"*/

/*
validate user input, and then passed the command to game model.
return validated command;
 */

class CommandParser{
public:
    //Command_Parser();
    //~Command_Parser();

    string processCommand(string &in);
    //bool is_Validated(std::vector<std::string>);

 private:
    vector<string> tokenizeInput(string &in);
    void toLowerCase(string &str);
    string invokeCommand()

   //  const string CommandSet[3] = {
   //  "move", "kill", "lookat"
   // };
  // std::vector<std::string> tokenizeInput(std::string in);
    //std::vector<std::string> input_tokens;
    //enum Command_Set{ MOVE, KILL, USE };
    /*may need to search for a file that lists of  */
   // bool lookup_Command_Set(std::string cmd);
   /* lookup_User_Command_Alias(std::String cmd, Player id);*/

};
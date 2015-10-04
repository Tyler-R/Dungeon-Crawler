#pragma once
#include <string>
#include <vector>
#include <boost/tokenizer.hpp>

/*include "player.h"*/

/*
validate user input, and then passed the command to game model.
return validated command;
 */

class Command_Parser{
public:
    Command_Parser();
    ~Command_Parser();
    void tokenize_input(std::string in);
    bool is_Validated(std::vector<std::string>);

prvivate:
    std::vector<std::string> input_tokens;
    enum Command_Set{ MOVE, KILL, USE };
    /*may need to search for a file that lists of  */
    bool lookup_Command_Set(std::string cmd);
   /* lookup_User_Command_Alias(std::String cmd, Player id);*/

};
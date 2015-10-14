#pragma once
#include <string>
#include <vector>
#include <boost/tokenizer.hpp>
#include "world.h"
// #include "CommandSet.h"


/*include "player.h"*/

/*
validate user input, and then passed the command to game model.
return validated command;
 */

class CommandParser{
public:

    CommandParser(World& worldModel);
    std::string processCommand(std::string &in);

 private:
    World world;
    std::vector<std::string> tokenizeInput(std::string &in);
    void toLowerCase(std::string &str);
    void reformatTokens(std::vector<std::string>& tokens);
    std::string validateMoveArgv(std::vector<std::string>& cmd);
    std::string validateLookArgv(std::vector<std::string>& cmd);


};
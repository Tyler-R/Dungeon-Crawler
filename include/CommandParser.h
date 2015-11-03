#pragma once
#include <string>
#include <vector>
#include <memory>
#include <boost/tokenizer.hpp>
// #include "CommandSet.h"


/*include "player.h"*/

/*
validate user input, and then passed the command to game model.
return validated command;
 */


class CommandParser{
public:

    std::string processCommand(std::string &in);


 private:
    std::vector<std::string> tokenizeInput(std::string &in);
    void toLowerCase(std::string &str);
    void reformatTokens(std::vector<std::string>& tokens);
    std::string validateMoveArgv(std::vector<std::string>& cmd);
    std::string validateLookArgv(std::vector<std::string>& cmd);
    std::string validaeAttackNPCArgv(std::vector<std::string>& cmd);
    std::vector<std::string> getGlobalCmdAlias(std::string generic_cmd);
    bool findMatch(std::vector<std::string> &alias, std::string &word);
    bool isMoveCmd(std::vector<std::string>& word);
    bool isLookCmd(std::vector<std::string>& word);
    bool isAttackNPCsCmd(std::vector<std::string>& word);
    bool isAliasCmdGlobal(std::vector<std::string>& word);

};

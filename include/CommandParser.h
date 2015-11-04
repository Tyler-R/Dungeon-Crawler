#pragma once
#include <string>
#include <vector>
#include <memory>
#include <boost/tokenizer.hpp>
// #include "CommandSet.h"

class CommandParser{
public:

    std::string processCommand(std::string &in);


 private:
    std::vector<std::string> tokenizeInput(std::string &in);
    void toLowerCase(std::string &str);
    void reformatTokens(std::vector<std::string>& tokens);
    bool findMatch(std::vector<std::string> &alias, std::string &word);
    std::vector<std::string> getGlobalCmdAlias(std::string generic_cmd);

    std::string validateMoveArgv(std::vector<std::string>& cmd);
    std::string validateLookArgv(std::vector<std::string>& cmd);
    std::string validateAttackNPCArgv(std::vector<std::string>& cmd);
    std::string validateTakeArgv(std::vector<std::string>& cmd);
    std::string validateUsdeArgv(std::vector<std::string>& cmd);
    std::string validateCheckArgv(std::vector<std::string>& cmd);
    std::string validateAliasArgv(std::vector<std::string>& cmd);


    bool isMoveCmd(std::vector<std::string>& word);
    bool isLookCmd(std::vector<std::string>& word);
    bool isAttackNPCsCmd(std::vector<std::string>& word);
    bool isTakeCmd(std::vector<std::string>& word);
    bool isUseCmd(std::vector<std::string>& word);
    bool isCheckCmd(std::vector<std::string>& word);
    bool isAliasCmd(std::vector<std::string>& word);


};

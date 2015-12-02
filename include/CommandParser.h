#pragma once
#include <string>
#include <vector>
#include <memory>
#include <boost/tokenizer.hpp>
#include "user.h"
#include "spellsLibrary.h"
// #include "CommandSet.h"

class CommandParser{
public:
    CommandParser();
    CommandParser(shared_ptr<User> player, shared_ptr<spellsLibrary> spellLibrary);
    std::string processCommand(std::string &in);


 private:
    shared_ptr<User> PlayerOne;
    shared_ptr<spellsLibrary> spellLibrary;


    std::vector<std::string> tokenizeInput(std::string &in);
    void toLowerCase(std::string &str);
    void reformatTokens(std::vector<std::string>& tokens);
    bool findMatch(std::vector<std::string> &alias, std::string &word);
    std::vector<std::string> getGlobalCmdAlias(std::string generic_cmd);

    //these will reference the world
    std::string validateMoveArgv(std::vector<std::string>& cmd);
    std::string validateLookArgv(std::vector<std::string>& cmd);
    std::string validateAttackNPCArgv(std::vector<std::string>& cmd);
    std::string validateTakeArgv(std::vector<std::string>& cmd);
    std::string validateUsdeArgv(std::vector<std::string>& cmd);
    std::string validateCheckArgv(std::vector<std::string>& cmd);
    std::string validateTossArgv(std::vector<std::string>& cmd);
    std::string validateSayArgv(std::vector<std::string>& cmd);
    std::string validateSpellArgv(std::vector<std::string> &cmd);


    //these not
    std::string validateAliasArgv(std::vector<std::string>& cmd);
    std::string validateHelpArgv(std::vector<std::string>& cmd);
    //interact with world
    bool isMoveCmd(std::vector<std::string>& word);
    bool isLookCmd(std::vector<std::string>& word);
    bool isAttackNPCsCmd(std::vector<std::string>& word);
    bool isTakeCmd(std::vector<std::string>& word);
    bool isUseCmd(std::vector<std::string>& word);
    bool isCheckCmd(std::vector<std::string>& word);
    bool isTossCmd(std::vector<std::string>& word);
    bool isSayCmd(std::vector<std::string>& word);
    bool isSpellCmd(std::vector<std::string>& word);


    bool isAliasCmd(std::vector<std::string>& word);
    bool isHelpCmd(std::vector<std::string>& word);

};

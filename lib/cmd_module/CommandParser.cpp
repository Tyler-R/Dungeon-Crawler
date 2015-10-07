#pragma once
#include "CommandParser.h"

/*
Command_Parser::Command_Parser(){

}
*/

std::vector<std::string> v; Command_Parser::tokenizeInput(std::string in){
    std::vector<std::string> usr_input;
    typedef boost::tokenizer<boost::char_separator<char> > tokenizer;
    boost:: char_separator<char> delm(" ");
    tokenizer tokens(in, delm);
    for(tokenizer::iterator token_itr = tokens.begin();
     token_itr != tokens.end(); ++token_itr){
        usr_input.push_back(*token_itr);
    }
    return usr_input;
}

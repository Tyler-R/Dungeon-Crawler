#include "CommandParser.h"
using namespace std;
/*
Command_Parser::Command_Parser(){

}
*/

vector<string> CommandParser::tokenizeInput(std::string in){
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

/*entry point for the cmd_module api*/
string CommandParser::processCommand(string in){
   toLowerCase(in);
   vector<string> words = tokenizeInput(in);
   cout<<"processing..."<<words.front()<<endl;
   if(words.front().compare("move") == 0){
        // cout<<words.front();
        return words.front();
   }
   else if(words.front().compare("kill") == 0){
        // cout<<words.front();
        return words.front();
   }
   else if(words.front().compare("lookat") == 0){
        // cout<<words.front();
        return words.front();
   }
   else {
    return "invalid command";
   }

}

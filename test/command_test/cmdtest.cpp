// char_sep_example_1.cpp
#include <iostream>
#include <string>
#include <vector>
#include <CommandParser.h>
#include "world.h"
// static const std::string[] COMMAND_SET = {
//   "move", "kill"
// };
std::vector<std::string> test(std::string in);
bool isMatch(std::string);

int main()
{
  std::string str;
  CommandParser cp;
  std::string response;

  std::cout<<response <<std::endl;
  while(1){
    std::cout << "enter a command: ";
    std::getline(std::cin, str);
    response = cp.processCommand(str);
    // std::cout<<"getting response.."<<std::endl;
    std::cout<<response<<std::endl;
  }

  // std::vector<std::string> tokenized_stuff = cp.tokenizeInput(str);
  // for(std::vector<std::string>::iterator itr = tokenized_stuff.begin(); itr != tokenized_stuff.end(); ++itr){
  //   std::cout<< *itr<< " ";
  //   std::cout<< std::endl;
  // }
  /*check the first word == the words in enum*/
  // std::cout<< isMatch(tokenized_stuff[0]);
  return EXIT_SUCCESS;
}


// bool isMatch(std::string fw){
//   std::locale loc;
//   for (std::string::size_type i = 0; i < fw.length(); ++i){
//     std::tolower(fw[i], loc);
//   }
//   for (auto word : COMMAND_SET){
//     return fw == word;
//   }
// }


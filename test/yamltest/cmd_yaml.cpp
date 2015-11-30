#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "yaml-cpp/yaml.h"


int main()
{
    std::string wordCommand ="";
    YAML::Node commands = YAML::LoadFile("command/Commands.yaml");
    // YAML::Value root = YAML::Parse("command/Commands.yaml");
    // cout << root;
    // vector<string> moveAlias;
    if(commands["move"]){
      int numberWords = commands["move"].size();
      // std:: cout << numberWords << std::endl;
      for(int i = 0; i < numberWords; i++ ){
        std::cout<<commands["move"][i].as<std::string>()<<std::endl;
      }

    }
    // YAML::Node moveCmd = commands["move"]["alias"];
    // for (int i = 0; i < moveCmd.size(); ++i) {
    //     cout<<i <<endl;
    //     moveAlias.push_back(moveCmd[i].as<string>());
    // }
    // for (auto &cmd : moveAlias){
    //     cout << cmd << endl;
    // }

    return 0;
}
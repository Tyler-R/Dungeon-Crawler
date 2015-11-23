#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "yaml-cpp/yaml.h"
using namespace std;


int main()
{

    YAML::Node commands = YAML::LoadFile("Commands.yaml");


    // vector<string> moveAlias;
    if(commands["move"]){
        cout<<"1"<<endl;
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

//Test run with g++ -I. -g npc_yamlparser.cpp -lyaml-cpp -std=c++11 -L. -o yamltest
// ./yamltest

#include "yaml-cpp/yaml.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// void ClassName::functionName(string name){

int main()
{
	using namespace std;

	YAML::Node allNode = YAML::LoadFile("smurf.yml");
	YAML::Node roomsNodes = allNode["ROOMS"];
	string roomsDescription;

	for(int i = 0; (unsigned)i < roomsNodes.size(); i++) {
		roomsDescription = " ";

		YAML::Node descriptionNode = roomsNodes[i]["desc"];
		for(int j = 0; j < descriptionNode.size(); j++){
			roomsDescription += descriptionNode[j].as<string>();
		}

		// YAML::Node doorsNode = roomsNodes[i]["doors"];
		// for(int j = 0; j < doorsNode.size(); j++){
		// 	YAML::Node doorsNode[j];
		// 	for(int k = 0; k < doorsNode[k]; k++){
		// 			doorsNode[k][desc];
		// 	}
		// }		

		

		cout <<"--New Room Created!--"<< endl;
		cout << roomsDescription << endl<<endl;
		// cout << NPCDescription << endl<<endl;
		// cout << NPCId << endl<<endl;

		// cout << "Keywords: " << endl;
		// for (auto & keyword : npcKeywords) {
		// 	cout << keyword << ", ";
		// }
		// cout << endl << endl <<NPCLongDesc << endl<<endl;
		// cout << NPCShortDesc << endl<<endl;

	}

}

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
	cout << "Hello World!" << endl;
	YAML::Node allNode = YAML::LoadFile("/home/jzzhang/textadventure/test/yamltest/me.yaml");
	YAML::Node npcNodes = allNode["NPCS"];

	string NPCDescription;
	string NPCId;
	vector<string> npcKeywords; 
	string NPCLongDesc;
	string NPCShortDesc;

	for(int i = 0; (unsigned)i < npcNodes.size(); i++) {
		NPCDescription ="";
		NPCId= "";
		npcKeywords.clear();
		NPCLongDesc ="";
		NPCShortDesc=" ";

		YAML::Node descriptionNode = npcNodes[i]["description"];
		for(int j = 0; j < descriptionNode.size(); j++){
			NPCDescription += descriptionNode[j].as<string>();
		}

		NPCId = npcNodes[i]["id"].as<string>();


		YAML::Node keywordsNode = npcNodes[i]["keywords"];
		for(int k = 0; k < keywordsNode.size(); k++){
			npcKeywords.push_back(keywordsNode[k].as<string>());
		}

		YAML::Node longdescNode = npcNodes[i]["longdesc"];
		for(int k = 0; k < longdescNode.size(); k++){
			NPCLongDesc += longdescNode[k].as<string>();
		}

		NPCShortDesc = npcNodes[i]["shortdesc"].as<string>(); 

		cout <<"--New NPC Created!--"<< endl;
		cout << NPCDescription << endl<<endl;
		cout << NPCId << endl<<endl;

		cout << "Keywords: " << endl;
		for (auto & keyword : npcKeywords) {
			cout << keyword << ", ";
		}
		cout << endl << endl <<NPCLongDesc << endl<<endl;
		cout << NPCShortDesc << endl<<endl;

	}
	cout << "Goodbye World!" << endl;
	return 0;
}
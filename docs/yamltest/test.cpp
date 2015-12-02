
//Test run with g++ -I. -g test.cpp -lyaml-cpp -std=c++11 -L. -o monsterstest
// ./monsterstest

#include "yaml-cpp/yaml.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main()
{
	using namespace std;

	YAML::Node allNode = YAML::LoadFile("smurf.yaml");
	YAML::Node npcNodes = allNode["NPCS"];
	// go through all NPCS blocks on yaml file (only read NPCS)

	for(int i = 0; (unsigned)i < npcNodes.size(); i++) {
		auto description = npcNodes[i]["description"];
		auto id = npcNodes[i]["id"];
		auto keywords = npcNodes[i]["keywords"];
		auto longdesc = npcNodes[i]["longdesc"];
		auto shortdesc = npcNodes[i]["shortdesc"]; 
		cout << description << endl << endl;
		cout << id << endl << endl;
		cout << keywords << endl << endl;
		cout << longdesc << endl << endl;
		cout << shortdesc << endl << endl;
	}
	// cout << endl << endl << npcNodes[0]["description"] << endl;


	// for(int i = 0; (unsigned)i < npcNodes.size(); i++) {
	// 	auto id = npcNodes[i]["id"];
	// 	cout << id << endl << endl;
	// }

	// cout << endl << endl << npcNodes[0]["description"] << endl;

	// for (int i = 0; (unsigned)i < rootNode.size(); i++) {

	// 	// get description
	// 	YAML::Node descriptionNode = rootNode[i]["description"];
	// 	std::string npcDescription;
	// 	for(int j = 0; (unsigned)j < descriptionNode.size(); j++){
	// 		npcDescription += descriptionNode[j].as<std::string>()+" ";
	// 		std::cout << npcDescription;
	// 	}
	// }
		// 	// get npc id
		// string npcID = rootNode[i]["id"].as<string>();
		// // get npc keyword (string or vector<string> ?)
		// string npcKeyword = rootNode[i]["keywords"].as<string>();
		// // get long desc
		// string npcLongDesc = rootNode[i]["longdesc"].as<string>();
		// // get short desc
		// string npcShortDesc = rootNode[i]["shortdesc"].as<string>();
		
		// // (the name of vector which store npc).push_back all informations read from yaml
		// npcVector.push_back(NPC(npcDescription,npcID,npcKeyword,npcLongDesc,npcShortDesc));
	return 0;
}

// // parameter name = the name of the yaml file
// void ClassName::functionName(string name){

// 	// path to find the yaml file
// 	string fileName="./PathToYaml/"+name+".yml";
	
// 	// load file to the allNode, which store all the information
// 	YAML::Node allNode = YAML::LoadFile(fileName);	

// 	// sets root node on 'any' category, such as NPCS, RESETS, ROOMS etc in the yaml file.
// 	YAML::Node rootNode = allNode["NPCS"];
	
// 	// go through all NPCS blocks on yaml file (only read NPCS)
// 	for (int i = 0; i < rootNode.size(); i++) {

// 		// get description
// 		YAML::Node descriptionNode = rootNode[i]["description"];
// 		string npcDescription;
// 		for(int j = 0; j < descriptionNode.size(); j++){
// 			npcDescription += descriptionNode[j].as<string>()+" ";
// 		}

// 		// get npc id
// 		string npcID = rootNode[i]["id"].as<string>();
// 		// get npc keyword (string or vector<string> ?)
// 		string npcKeyword = rootNode[i]["keywords"].as<string>();
// 		// get long desc
// 		string npcLongDesc = rootNode[i]["longdesc"].as<string>();
// 		// get short desc
// 		string npcShortDesc = rootNode[i]["shortdesc"].as<string>();
		
// 		// (the name of vector which store npc).push_back all informations read from yaml
// 		npcVector.push_back(NPC(npcDescription,npcID,npcKeyword,npcLongDesc,npcShortDesc));
		
// 	}
// }



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

	YAML::Node allNode = YAML::LoadFile("smurf.yaml");
	YAML::Node npcNodes = allNode["NPCS"];
	// // go through all NPCS blocks on yaml file (only read NPCS)
	
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
		//string npcDescription;
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
		


		// string description = npcNodes[i]["description"].as<string>();

		// createNPC()
		// cout << description << endl << endl;
		// cout << id << endl << endl;
		//npcKeywords.push_back(keywords);
		//cout << "Keyword" << npcKeywords << endl << endl;
		//cout << "Keyword" << npcKeywords << endl << endl;
	
		// cout << longdesc << endl << endl;
		// cout << shortdesc << endl << endl;

// void createNPC(){


// }

	// cout << endl << endl << npcNodes[0]["description"] << endl;
// 		string npcID = rootNode[i]["id"].as<string>();
// 		// get npc keyword (string or vector<string> ?)
// 		string npcKeyword = rootNode[i]["keywords"].as<string>();
// 		// get long desc
// 		string npcLongDesc = rootNode[i]["longdesc"].as<string>();
// 		// get short desc
// 		string npcShortDesc = rootNode[i]["shortdesc"].as<string>();
		
// 		// (the name of vector which store npc).push_back all informations read from yaml
// 		npcVector.push_back(NPC(npcDescription,npcID,npcKeyword,npcLongDesc,npcShortDesc));

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
		
// 	}
// }


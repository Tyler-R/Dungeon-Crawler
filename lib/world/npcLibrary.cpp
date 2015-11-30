//Created by Sarah Kim Dao and Jason Zhang

#include "npcLibrary.h"
#include "yaml-cpp/yaml.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits.h>
npcLibrary::npcLibrary(){
	cout << "--Creating NPC Library ...";
	parseYaml();
	cout << "Done!" << endl;
}

// npcLibrary::~npcLibrary(){

// }

using namespace std;

shared_ptr<NPC> npcLibrary::create(string id,string description,string longDesc,string shortDesc,vector<string> keywords){
	shared_ptr<NPC> npc (new NPC(id));
	npc->addKeywords(keywords);
	npc->addDescription(description);
	npc->addShortDesc(shortDesc);
	npc->addLongDesc(longDesc);
	return npc;
}

void npcLibrary::addNPC(shared_ptr<NPC> npc){
	npcList.push_back(npc);
}

shared_ptr<NPC> npcLibrary::get(string id){
	for (auto & npc :npcList){
		if (npc->getID() == id){
			return npc;
		}
	}
	return nullptr;
}

shared_ptr<NPC> npcLibrary::spawn(string id){
	for (auto & npc :npcList){
		if (npc->getID() == id){
			return create(npc->getID(),npc->getDescription(),npc->getLongDesc(),npc->getShortDesc(),npc->getKeyword());
		}
	}
	return nullptr;
}

vector<shared_ptr<NPC>> npcLibrary::getNPCList(){
	return npcList;
}



void npcLibrary::parseYaml(){
	char filePath[PATH_MAX + 1]; 
    char *res = realpath("gameYaml/midgaard.yaml", filePath);

	YAML::Node allNode = YAML::LoadFile(filePath);
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
			NPCDescription += "\n";
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
    	addNPC(create(NPCId,NPCDescription,NPCLongDesc,NPCShortDesc,npcKeywords));

	}


}
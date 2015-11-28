
#include "itemLibrary.h"
#include "yaml-cpp/yaml.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>


using namespace std;

shared_ptr<ITEM> itemLibrary::create(string objectId, vector<string>  objectKeywords, vector<string> objectLongDesc, string objectShortDesc, string exra){
	shared_ptr<ITEM> item (new ITEM(id));
	// item->addKeywords(keywords);
	// item->addDescription(description);
	// item->addShortDesc(shortDesc);
	// item->addLongDesc(longDesc);
	return item;
}

void npcLibrary::addItem(shared_ptr<ITEM> npc){
	itemList.push_back(item);
}

shared_ptr<ITEM> itemLibrary::get(string id){
	for (auto & item :itemList){
		if (npc->getID() == id){
			return item;
		}
	}
	return NULL;
}

void itemLibrary::parseYaml(){
	for(int i = 0; (unsigned)i < npcNodes.size(); i++) {
	YAML::Node allNode = YAML::LoadFile("gameYaml/midgaard.yaml");
	YAML::Node objectNodes = allNode["OBJECTS"];
	
	string extra;
	string objectId;
	vector<string> objectKeywords; 
	vector<string> objectLongDesc;
	string objectShortDesc;

	for(int i = 0; (unsigned)i < objectNodes.size(); i++) {
		extra =" ";
		objectId= " ";
		objectKeywords.clear();
		objectLongDesc.clear();
		objectShortDesc=" ";


		if (objectsNodes[i]["extra"]){
			extra = objectsNodes[i]["extra"].as<string>();
		}		
		else {
			extra = "No Extra Descripton";
		}			

		objectId = objectNodes[i]["id"].as<string>();


		YAML::Node keywordsNode = objectNodes[i]["keywords"];
		for(int k = 0; k < keywordsNode.size(); k++){
			objectKeywords.push_back(keywordsNode[k].as<string>());
		}

		YAML::Node longdescNode = objectNodes[i]["longdesc"];
		for(int k = 0; k < longdescNode.size(); k++){
			objectLongDesc.push_back(longdescNode[k].as<string>());
		}

		objectShortDesc = objectNodes[i]["shortdesc"].as<string>(); 

		
		cout << "Object Id is " << objectId << endl << endl;

		cout << "Object Keywords: " << endl;
		for (auto & keyword : objectKeywords) {
			cout << "-" << keyword << endl;
		}
		cout << endl;

		cout << "longdescs: " << endl;
		for (auto & longdesc : objectLongDesc) {
			cout << longdesc << endl;
		}
		cout << endl;

		cout << "shortdesc: " << objectShortDesc << endl<<endl;

    	addItem(create(NPCId,NPCDescription,NPCLongDesc,NPCShortDesc,npcKeywords));

	}
}

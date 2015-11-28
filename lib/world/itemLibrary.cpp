
#include "itemLibrary.h"
#include "yaml-cpp/yaml.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>


using namespace std;

shared_ptr<ITEM> itemLibrary::create(string objectId, vector<string> objectKeywords, vector<string> objectLongDesc, string objectShortDesc, string extra){
	shared_ptr<ITEM> item (new ITEM(objectId));
	item->addKeywords(objectKeywords);
	item->addLongDesc(objectLongDesc);
	item->addShortDesc(objectShortDesc);
	item->addExtra(extra);
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
	YAML::Node allNode = YAML::LoadFile("midgaard.yml");
	YAML::Node objectNodes = allNode["OBJECTS"];
	
	string objectId;
	vector<string> objectKeywords; 
	vector<string> objectLongDesc;
	string objectShortDesc;
	vector <string> extra;

	for(int i = 0; (unsigned)i < objectNodes.size(); i++) {
		extra.clear();
		objectId= " ";
		objectKeywords.clear();
		objectLongDesc.clear();
		objectShortDesc=" ";

		cout <<"--New object Created!--"<< endl;

		YAML::Node extraNode = objectNodes[i]["extra"];
		for (int m = 0; m < extraNode.size(); m++){
			if (extraNode[m]["desc"]){
				YAML::Node extraDescNode = extraNode[m]["desc"];
				for(int k = 0; k < extraDescNode.size(); k++){
					extra.push_back(extraDescNode[k].as<string>());
				}	
			} else {
			extra.clear();
			}			
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
		for (auto & extraDesc : extra) {
			cout << extraDesc << endl;
		}
		cout << endl;
		cout << "shortdesc: " << objectShortDesc << endl<<endl;

    	addItem(create(NPCId,NPCDescription,NPCLongDesc,NPCShortDesc,npcKeywords));

	}
}

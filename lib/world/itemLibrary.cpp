
#include "itemLibrary.h"
#include "yaml-cpp/yaml.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>


using namespace std;

shared_ptr<Item> itemLibrary::create(string objectId, vector<string> objectKeywords, string objectLongDesc, string objectShortDesc, string extra){
	shared_ptr<Item> item (new item(string objectId));
	item->addKeywords(objectKeywords);
	item->addLongDescs(objectLongDesc);
	item->addShortDesc(objectShortDesc);
	item->addExtraDescs(extra);
	return item;
}

void itemLibrary::addItem(shared_ptr<Item> item){
	itemList.push_back(item);
}

shared_ptr<Item> itemLibrary::get(string id){
	for (auto & item :itemList){
		if (item->getID() == id){
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
	//vector<string> objectLongDesc;
	string objectLongDesc;
	string objectShortDesc;
	//vector <string> extra;
	string extra;

	for(int i = 0; (unsigned)i < objectNodes.size(); i++) {
		extra.clear();
		objectId= " ";
		objectKeywords.clear();
		objectLongDesc.clear();
		objectShortDesc=" ";

		YAML::Node extraNode = objectNodes[i]["extra"];
		for (int m = 0; m < extraNode.size(); m++){
			if (extraNode[m]["desc"]){
				YAML::Node extraDescNode = extraNode[m]["desc"];
				// for(int k = 0; k < extraDescNode.size(); k++){
				// 	extra.push_back(extraDescNode[k].as<string>());
				// }
				for(int k = 0; k < extraDescNode.size(); k++) {
					extra += extra[k].as<string>();
					extra += "\n";
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
		// for(int k = 0; k < longdescNode.size(); k++){
		// 	objectLongDesc.push_back(longdescNode[k].as<string>());
		// }
		for(int k = 0; k < longdescNode.size(); k++) {
			objectLongDesc += objectLongDesc[k].as<string>();
			objectLongDesc += "\n";
		}

		objectShortDesc = objectNodes[i]["shortdesc"].as<string>(); 


    	addItem(create(objectId,objectKeywords,objectLongDesc, objectShortDesc, extra));

	}
}

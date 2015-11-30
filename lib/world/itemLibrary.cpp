
#include "itemLibrary.h"
#include "yaml-cpp/yaml.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits.h>

using namespace std;

itemLibrary::itemLibrary(){
	cout << "--Creating Item Library ...";
	parseYaml();
	cout << "Done!" << endl;
}

shared_ptr<Item> itemLibrary::create(string objectId, vector<string> objectKeywords, string objectLongDesc, string objectShortDesc, string extra){
	shared_ptr<Item> item (new Item(objectId));
	item->addKeywords(objectKeywords);
	item->addLongDesc(objectLongDesc);
	item->addShortDesc(objectShortDesc);
	item->addExtraDesc(extra);
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
	return nullptr;
}

shared_ptr<Item> itemLibrary::spawn(string id){
	for (auto & item :itemList){
		if (item->getID() == id){
			return create(item->getID(),item->getKeyword(),item->getLongDesc(),item->getShortDesc(),item->getExtraDesc());
		}
	}
	return nullptr;
}

vector<shared_ptr<Item>> itemLibrary::getItemList(){
	return itemList;
}

void itemLibrary::parseYaml(){
	char filePath[PATH_MAX + 1]; 
    char *res = realpath("gameYaml/midgaard.yaml", filePath);

	YAML::Node allNode = YAML::LoadFile(filePath);
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
		objectLongDesc= " ";
		objectShortDesc=" ";

		YAML::Node extraNode = objectNodes[i]["extra"];
		for (int m = 0; m < extraNode.size(); m++){
			if (extraNode[m]["desc"]){
				YAML::Node extraDescNode = extraNode[m]["desc"];
				// for(int k = 0; k < extraDescNode.size(); k++){
				// 	extra.push_back(extraDescNode[k].as<string>());
				// }
				for(int k = 0; k < extraDescNode.size(); k++) {
					extra += extraDescNode[k].as<string>();
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
			objectLongDesc += longdescNode[k].as<string>();
			objectLongDesc += "\n";
		}

		objectShortDesc = objectNodes[i]["shortdesc"].as<string>(); 


    	addItem(create(objectId,objectKeywords,objectLongDesc, objectShortDesc, extra));

	}
}

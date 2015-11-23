#include "yaml-cpp/yaml.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "item.h"
#include <memory>

using namespace std;

class itemLibrary{
	public:
		vector<shared_ptr<ITEM>> npcList;
		shared_ptr<ITEM> create(string id,string description,string longDesc,string shortDesc,vector<string> keywords);
		void addItem(shared_ptr<ITEM>);
		shared_ptr<ITEM> get(string id);
		void parseYaml();

};
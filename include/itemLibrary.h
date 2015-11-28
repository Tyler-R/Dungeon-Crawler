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
		vector<shared_ptr<ITEM>> itemList;
		shared_ptr<ITEM> create(string extra, string objectId, vector<string> objectKeywords, vector<string> objectLongDesc, string objectShortDesc);
		void addItem(shared_ptr<ITEM>);
		shared_ptr<ITEM> get(string objectId);
		void parseYaml();

};
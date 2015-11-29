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
		itemLibrary();
		vector<shared_ptr<Item>> itemList;
		shared_ptr<Item> create(string objectId, vector<string> objectKeywords, string objectLongDesc, string objectShortDesc, string extra);
		void addItem(shared_ptr<Item>);
		shared_ptr<Item> get(string objectId);
		void parseYaml();

		shared_ptr<Item> spawn(string id);

};
#include "yaml-cpp/yaml.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "reset/Reset.h"
#include "reset/NPCReset.h"
#include "reset/DoorReset.h"
#include "reset/ItemReset.h"
#include <memory>

using namespace std;

class resetLibrary{
	public:
		resetLibrary();
		vector<shared_ptr<Reset>> resetList;
		vector<shared_ptr<Reset>> resetItemList;
		vector<shared_ptr<Reset>> resetNPCList;
		vector<shared_ptr<Reset>> resetDoorsList;

		// void resetSpliter(shared_ptr<Reset>);
		shared_ptr<Reset> create(string action,string comment,string resetId,string limit, string room, string slot, string lock);

		void addItemReset(shared_ptr<Reset>);
		void addNPCReset(shared_ptr<Reset>);
		void addDoorsReset(shared_ptr<Reset>);
		// shared_ptr<Reset> get(string resetId);
		void parseYaml();

};
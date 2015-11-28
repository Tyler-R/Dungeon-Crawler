#include "yaml-cpp/yaml.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "reset/NPCReset.h"
#include "reset/DoorReset.h"
#include "reset/ItemReset.h"
#include <memory>

using namespace std;

class resetLibrary{
	public:
		vector<shared_ptr<RESET>> resetList;
		shared_ptr<RESET> create(string action, string comment, string resetId, string limit, string room, string slot);
		void addReset(shared_ptr<RESET>);
		shared_ptr<RESET> get(string resetId);
		void parseYaml();

};
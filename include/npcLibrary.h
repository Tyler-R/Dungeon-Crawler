#include "yaml-cpp/yaml.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "npc.h"
#include <memory>

using namespace std;

class npcLibrary{
	private:
		

	public:
		//npcLibrary();
		//~npcLibrary();
		vector<shared_ptr<NPC>> npcList;
		shared_ptr<NPC> create(string id,string description,string longDesc,string shortDesc,vector<string> keywords);
		void addNPC(shared_ptr<NPC>);
		shared_ptr<NPC> get(string id);
		void parseYaml();

};
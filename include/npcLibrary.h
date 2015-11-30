//Created by Sarah Kim Dao and Jason Zhang
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
		vector<shared_ptr<NPC>> npcList;
		shared_ptr<NPC> create(string id,string description,string longDesc,string shortDesc,vector<string> keywords);
		void addNPC(shared_ptr<NPC>);		
		void parseYaml();

	public:
		npcLibrary();
		//~npcLibrary();

		shared_ptr<NPC> get(string id);
		shared_ptr<NPC> spawn(string id);
		vector<shared_ptr<NPC>> getNPCList();
		

};
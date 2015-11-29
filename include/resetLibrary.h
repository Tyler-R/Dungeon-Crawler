#pragma once
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
		resetLibrary(vector<shared_ptr<NPC>> npcList, vector<shared_ptr<Room>> roomList);
		vector<shared_ptr<Reset>> resetList;

		// void resetSpliter(shared_ptr<Reset>);
		shared_ptr<Reset> create(string action,string comment,string resetId,string limit, string room, string slot, string lock);

		vector<shared_ptr<Reset>> getResetList();
		void addItemReset(shared_ptr<Reset>);
		void addNPCReset(shared_ptr<Reset>);
		void addDoorsReset(shared_ptr<Reset>);
		// shared_ptr<Reset> get(string resetId);
		shared_ptr<NPC> searchNPC(string npcID, vector<shared_ptr<NPC>> npcList);
		shared_ptr<Room> searchRoom(string roomID, vector<shared_ptr<Room>> roomList);
		void parseYaml(vector<shared_ptr<NPC>> npcList, vector<shared_ptr<Room>> roomList);


};
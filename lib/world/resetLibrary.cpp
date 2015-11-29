
#include "resetLibrary.h"
#include "yaml-cpp/yaml.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>


using namespace std;

resetLibrary::resetLibrary(vector<shared_ptr<NPC>> npcList, vector<shared_ptr<Room>> roomList){
	parseYaml(npcList, roomList);
}

// shared_ptr<Reset> resetLibrary::create(string action,string comment,string resetId,string limit, string room, string slot, string lock){
// 	// shared_ptr<Reset> reset (new Reset(action, comment, resetId, limit, room, slot, lock));
// 	// reset->addId(resetId);

// 	// return reset;


// 	string actionType = action;
// 	if(actionType.compare("npc") == 0 || actionType.compare("equip") == 0 || actionType.compare("give") == 0){

// 		// use id to find NPC that will be placed in room
// 		// clone the NPC
// 		// use Room to find room reset will be placed in
// 		// take limit on its own

// 		// place NPC, Room, and NPC limit into a new reset
// 		shared_ptr<Reset> reset (new NPCReset(room, resetId, limit));
// 		addNPCReset(reset);
// 	}else if (actionType.compare("object") == 0 || actionType.compare("put") == 0) {
// 		shared_ptr<Reset> reset (new ItemReset(room, resetId));
// 		addObjectReset(reset);
// 	}else {
// 		shared_ptr<Reset> reset (new DoorReset(room, resetId, lock));
// 		addDoorsReset(reset);
// 	}
// }



// void resetLibrary::addReset(shared_ptr<Reset> reset){
// 	resetList.push_back(reset);
// }

vector<shared_ptr<Reset>> resetLibrary::getResetList(){
	return resetList;
}


shared_ptr<NPC> resetLibrary::searchNPC(string npcID, vector<shared_ptr<NPC>> npcList){
	for(auto & npc : npcList){
		if (npcID == npc->getID()){
			return npc;
		}
	}
	return NULL;
}

shared_ptr<Room> resetLibrary::searchRoom(string roomID, vector<shared_ptr<Room>> roomList){
	for(auto & room:roomList){
		if (roomID == room->getId()){
			return room;
		}
	}
	return NULL;
}

// shared_ptr<Reset> resetLibrary::get(string id){
// 	for (auto & reset :resetList){
// 		if (reset->getID() == resetId){
// 			return reset;
// 		}
// 	}
// 	return NULL;
// }


void resetLibrary::parseYaml(vector<shared_ptr<NPC>> npcList, vector<shared_ptr<Room>> roomList){
	YAML::Node allNode = YAML::LoadFile("gameYaml/midgaard.yaml");
	YAML::Node resetNodes = allNode["RESETS"];

	string action;
	string comment; 
	string resetId;
	string limit;
	string room;
	string slot;
	string lock;




	for(int i = 0; (unsigned)i < resetNodes.size(); i++) {
		action = " ";
		comment = " ";
		resetId = " ";
		limit = " ";
		room = " ";
		slot = " ";
		lock = " ";

		action = resetNodes[i]["action"].as<string>();
		resetId = resetNodes[i]["id"].as<string>();


		YAML::Node commentNode = resetNodes[i]["comment"];
		if(commentNode != NULL){
			comment = commentNode.as<string>();
		}
		else {
			comment = "NULL";
		}
		
		YAML::Node limitNode = resetNodes[i]["limit"];
		if(limitNode != NULL){
			limit = limitNode.as<string>();
		}
		else {
			limit = "NULL";
		}

		YAML::Node roomNode = resetNodes[i]["room"];
		if(roomNode != NULL){
			room = roomNode.as<string>();
		}
		else {
			room = "NULL";
		}


		YAML::Node slotNode = resetNodes[i]["slot"];
		if(slotNode != NULL){
			slot = slotNode.as<string>();
		}
		else {
			slot = "NULL";
		}

		YAML::Node lockNode = resetNodes[i]["lock"];
		if(lockNode != NULL){
			lock = lockNode.as<string>();
		}
		else {
			lock = "NULL";
		}

		//Sarah's Notes: Use if statements to check what the reset type is, then create the appropriate reset subclass
		if (action == "npc"){
			resetList.push_back(make_shared<NPCReset>(searchRoom(room, roomList),searchNPC(resetId,npcList), 3));
			make_shared<NPCReset>(searchRoom(room, roomList),searchNPC(resetId,npcList), stoi(limit));
		}

		if (action == "equip"){
			//Create Equip Reset
		}

		if (action == "give"){
			//Create Give Reset
		}

		if (action == "object"){
			//Create Object Reset
		}

		if (action == "put"){
			//Create Put Reset
		}

		if (action == "door"){
			//Create Door Reset
		}

    	//create(action, comment, resetId,limit, room, slot, lock);
    	// resetSpliter(resetList);

	}

}


#include "resetLibrary.h"
#include "yaml-cpp/yaml.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>


using namespace std;

resetLibrary::resetLibrary(){
	parseYaml();
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


void resetLibrary::addItemReset(shared_ptr<Reset> reset){
	resetItemList.push_back(reset);
}

void resetLibrary::addNPCReset(shared_ptr<Reset> reset){
	resetNPCList.push_back(reset);
}

void resetLibrary::addDoorsReset(shared_ptr<Reset> reset){
	resetDoorsList.push_back(reset);
}


// shared_ptr<Reset> resetLibrary::get(string id){
// 	for (auto & reset :resetList){
// 		if (reset->getID() == resetId){
// 			return reset;
// 		}
// 	}
// 	return NULL;
// }

void resetLibrary::parseYaml(){
	YAML::Node allNode = YAML::LoadFile("gameYaml/smurf.yaml");
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
	

    	create(action, comment, resetId,limit, room, slot, lock);
    	// resetSpliter(resetList);

	}
}

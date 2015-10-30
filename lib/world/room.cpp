/*Room CLASS

This is a game class that contains attributes and methods for each room contained in the game world.

Created By: Sarah Kim Dao
*/

#include <strings.h>
#include "room.h"



Room::Room(){
	id = "no_id";
	name = "no_name";
	desc = "no_desc";
	extDesc = "no_extDesc";
}

Room::Room(string inputId, string inputName, string inputDesc, string inputExtDesc){
	id = inputId;
	name = inputName;
	desc = inputDesc;
	extDesc = inputExtDesc;

	keywordList.push_back(inputName);
}

Room::Room(Room &room){
	id = room.getId();
	name = room.getName();
	desc = room.getDesc();
	extDesc = room.getExtDesc();

	for (auto & keyword : room.getKeywords()) {
	    keywordList.push_back(keyword);
	}

	for (auto & door : room.getDoorList()) {
	    doorList.push_back(door);
	}

}

Room::~Room(){
	for (auto & door : doorList) {
	    delete door;
	}
}

string Room::getId(){
	return id;
}

string Room::getName(){
	return name;
}

string Room::getDesc(){
	return desc;
}

string Room::getExtDesc(){
	return extDesc;
}


vector<string> Room::getKeywords(){
	return keywordList;
}

vector<NPC*> Room::getNPCs(){
	return npcList;
}

vector<Item*> Room::getItems(){
	return itemList;
}


void Room::setId(string s){
	id = s;
}

void Room::setName(string s){
	name = s;
}

void Room::setDesc(string s){
	desc = s;
}
void Room::setExtDesc(string s){
	extDesc = s;
}


void Room::addKeyword(string s){
	keywordList.push_back(s);
}

void Room::addKeywords(vector<string> inputKeywords){
	for (auto & keyword : inputKeywords) {
	    addKeyword(keyword);
	}
}

void Room::removeKeyword(string s){
	//
}

bool Room::findKeyword(string s){
	for (auto & keyword : keywordList) {
		if(0 == strcasecmp(s.c_str(), keyword.c_str())){
			return true;
	   	}
	}
		return false;
}

void Room::printKeywords(){ //To be used by the Room's Test Module only!
	for (auto & keyword : keywordList) {
	    cout << keyword << endl;
	}
}

vector<Door*> Room::getDoorList(){
	return doorList;
}

//LookAround

vector<string> Room::getDoorDescList(){

	vector<string> doorDescriptions;

	for (auto & door : doorList) {
	    doorDescriptions.push_back(door->getDesc());
	}

	return doorDescriptions;

}



vector<string> Room::getObjList(){
	vector<string> objList;
	for (auto & door : doorList) {
	    objList.push_back(door->getLeadsTo()->getName());
	}
	return objList;
}

string Room::lookAround(){


		string objRoom = "";

		/*
		for(auto &str: npcList){
			objRoom += str->getName() + " ";
		}
		objRoom = "there are " + objRoom + "in the room"+ '\n';
		*/

		return getExtDesc()+ '\n' + objRoom;

	}

string Room::lookAt(string objName){


	if ( findKeyword(objName) ){
		return extDesc;
	}


	for (auto & door : doorList) {
		if ( door->getLeadsTo()->findKeyword(objName)){
			return door->getLeadsTo()->getDesc();
		}
	}

	for (auto & door : doorList) {
		if(door->findKeyword(objName)){
			return door->getDesc();
		}s
	}

	/*
	for (auto &npc : npcList){
		if(npc->findKeyword(objName)){
			return npc->getDesc();
		}
	}

	for (auto &item : itemList){
		if(item->findKeyword(objName)){
			return item->getDesc();
		}
	}
	*/

	return "\""+objName+"\""+" not found!\n";

}

void Room::setDoorState(int doorNumber, string newState) {
	doorList[doorNumber]->setState(newState); // probably needs tweaking
}

//void Room::createNPC(){
		/*
		NPC* monster = new NPC("monster","id:111");
		NPC* creature = new NPC("creature","id:222");

		npcList.push_back(monster);
		npcList.push_back(creature);
		*/
//}


void Room::addDoor(string inputId,string inputDir, string inputDesc, shared_ptr<Room>inputRoom){
	doorList.push_back(new Door(inputId,inputDir,inputDesc, inputRoom));
}

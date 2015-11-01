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

vector<shared_ptr<NPC>> Room::getNPCs(){
	return npcList;
}

vector<shared_ptr<Item>> Room::getItems(){
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


vector<string> Room::getObjKeywords(string objName){ //Gets a List of an Object's Keywords.
	vector <string> objKeywords;

	if ( findKeyword(objName) ){
		return getKeywords();
	}


	for (auto & door : doorList) {
		if ( door->findKeyword(objName)){
			return door->getKeywords();
		}
	}

	for (auto & npc : npcList) {
		if ( npc->searchKeyword(objName)){
			return npc->getKeyword();
		}
	}
}

void Room::addDoor(string inputId,string inputDir, string inputDesc, shared_ptr<Room>inputRoom){
	doorList.push_back(new Door(inputId,inputDir,inputDesc, inputRoom));
}

vector<Door*> Room::getDoorList(){
	return doorList;
}

//LookAround

vector<string> Room::getDoorDescList(){
	//This method returns a description of all of the room's doors.
	vector<string> doorDescriptions;

	for (auto & door : doorList) {
	    doorDescriptions.push_back(door->getDesc());
	}

	return doorDescriptions;

}

vector<string> Room::getObjList(){
	//This method returns a list of strings containing the names of every door, npc, item, and user in the room.
	vector<string> objList;
	for (auto & door : doorList) {
	    objList.push_back(door->getLeadsTo()->getName());
	}

	for (auto & npc : npcList) {
	    objList.push_back(npc->getName());
	}
	return objList;
}

string Room::lookAround(){
		//This method is used if the user types the "look <noun>" command and <noun> is their current room.

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
	//This method is used if the user types the "look <noun>" command.  <noun> can be a valid keyword.

	if ( findKeyword(objName) ){
		return extDesc;
	}


	for (auto & door : doorList) {
		if ( door->getLeadsTo()->findKeyword(objName)){
			return door->getLeadsTo()->getDesc();
		}
	}

	for (auto & npc : npcList) {
		if ( npc->searchKeyword(objName)){
			return npc->getLongDesc();
		}
	}


	/*
	for (auto &item : itemList){
		if(item->findKeyword(objName)){
			return item->getDesc();
		}
	}
	*/

	return "\""+objName+"\""+" not found!\n";

}

void Room::setDoorState(int doorNumber, string newState) {
	assert(doorNumber < doorList.size());
	doorList[doorNumber]->setState(newState); // probably needs tweaking
}

void Room::createNPC(){
		//Will create new instances of an NPC to place into room.
		//This is the function that should eventually Parse from YAML file and take input strings to create NPCs.
		// 'Butler Jeeves' is just a hard-coded example for testing purposes.

		shared_ptr<NPC> npc( new NPC("001"));
		npc->setName("Butler Jeeves");
		npc->addShortDesc("There is butler standing nearby.");
		npc->addLongDesc("The butler is busy cleaning up the lobby.");
		npc->addKeyword("butler");
		npc->addKeyword("servant");

		addNPC(npc);

}

void Room::addNPC(shared_ptr<NPC> npc) {
	npcList.push_back(npc);
}

void Room::createItem(){
		//Will create new instances of an NPC to place into room.
		//This is the function that should eventually Parse from YAML file and take input strings to create NPCs.
		// 'Potion' is just a hard-coded example for testing purposes.

		//shared_ptr<Item> item( new Item("001"));

		//addItem(item);
}

void Room::addItem(shared_ptr<Item> item){
	itemList.push_back(item);
}

bool Room::doesItemExist(string itemID) {
	for(auto &item : itemList) {
		if(itemID.compare(item->getID()) == 0) {
			return true;
		}
	}

	return false;
}

int Room::getNumberOfNPCsWithID(string npcID) {
	int npcCount = 0;

	for(auto &npc : npcList) {
		if(npc->getID().compare(npcID) == 0) {
			npcCount++;
		}
	}

	return npcCount;
}	

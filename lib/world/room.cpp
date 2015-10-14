/*Room CLASS

This is a game class that contains attributes and methods for each room contained in the game world.

Created By: Sarah Kim Dao
*/

#include "room.h"


Room::Room(){ 
	name = "no_name";
	desc = "no_desc";
	extDesc = "no_extDesc";

	north = new Door;
	setNorth(NULL, "You see nothing to the north.");

	south = new Door;
	setSouth(NULL, "You see nothing to the south.");

	east = new Door;
	setEast(NULL, "You see nothing to the east.");

	west = new Door;
	setWest(NULL, "You see nothing to the west.");

	up = new Door;
	setUp(NULL, "You see nothing in the upward direction.");

	down = new Door;
	setDown(NULL, "You see nothing in the downward direction.");

}

Room::Room(string input_name, string input_desc, string input_extDesc){ 
	name = input_name;
	desc = input_desc;
	extDesc = input_extDesc;

	north = new Door;
	setNorth(NULL, "You see nothing to the north.");

	south = new Door;
	setSouth(NULL, "You see nothing to the south.");

	east = new Door;
	setEast(NULL, "You see nothing to the east.");

	west = new Door;
	setWest(NULL, "You see nothing to the west.");

	up = new Door;
	setUp(NULL, "You see nothing in the upward direction.");

	down = new Door;
	setDown(NULL, "You see nothing in the downward direction.");
}

Room::Room(Room &obj){
	name = obj.getName();
	desc = obj.getDesc();
	extDesc = obj.getExtDesc();

	north = new Door;
	setNorth(obj.getNorth().leadsTo, obj.getNorth().desc);

	south = new Door;
	setSouth(obj.getSouth().leadsTo, obj.getSouth().desc);

	east = new Door;
	setEast(obj.getEast().leadsTo, obj.getEast().desc);

	west = new Door;
	setWest(obj.getWest().leadsTo, obj.getWest().desc);

	up = new Door;
	setUp(obj.getUp().leadsTo, obj.getUp().desc);

	down = new Door;
	setDown(obj.getDown().leadsTo, obj.getDown().desc);
}

/*Room::Room(char id){ 

}*/

Room::~Room(){
	//setNorth(NULL, "You see nothing to the north.");
	delete north;
	
	//setSouth(NULL, "You see nothing to the south.");
	delete south;
	
	//setEast(NULL, "You see nothing to the east.");
	delete east;

	//setWest(NULL, "You see nothing to the west.");
	delete west;

	//setUp(NULL, "You see nothing in the upward direction.");
	delete up;

	//setDown(NULL, "You see nothing in the downward direction.");
	delete down;

}

//string Room::getId(){
//	return id;
//}

string Room::getName(){
	return name;
}

string Room::getDesc(){
	return desc;
}

string Room::getExtDesc(){
	return extDesc;
}

vector<NPC*> Room::getNPCs(){
	return npcList;
}

/*	

vector<keyword> Room::getKeywords(){

}
	
vector<player> Room::getPlayers(){

}

vector<monster> Room::getMonsters(){

}
*/


//void Room::getId(string s){
//	id = s;
//}

void Room::setName(string s){
	name = s;
}

void Room::setDesc(string s){
	desc = s;
}
void Room::setExtDesc(string s){
	extDesc = s;
}


/*		
void Room::setPlayers(vector<Player> p){
	playerPop = p;
}

void Room::setMonsters(vector<monster> m){
	monsterPop = m;
}

void Room::setKeywords(vector<monster> m){
	monsterPop = m;
}
*/


void Room::setNorth(Room *input_id, string input_desc){
	north->leadsTo = input_id;
	north->desc = input_desc;
}

void Room::setSouth(Room *input_id, string input_desc){
	south->leadsTo = input_id;
	south->desc = input_desc;
}

void Room::setEast(Room *input_id, string input_desc){
	east->leadsTo = input_id;
	east->desc = input_desc;
}	

void Room::setWest(Room *input_id, string input_desc){
	west->leadsTo = input_id;
	west->desc = input_desc;
}

void Room::setUp(Room *input_id, string input_desc){
	up->leadsTo = input_id;
	up->desc = input_desc;
}

void Room::setDown(Room *input_id, string input_desc){
	down->leadsTo = input_id;
	down->desc = input_desc;
}


Room::Door Room::getNorth(){
	return *north;
}

Room::Door Room::getSouth(){
	return *south;
}

Room::Door Room::getEast(){
	return *east;
}

Room::Door Room::getWest(){
	return *west;
}

Room::Door Room::getUp(){
	return *up;
}

Room::Door Room::getDown(){
	return *down;
}


string Room::lookNorth(){ 
	return north->desc;
}

string Room::lookSouth(){
	return south->desc;
}

string Room::lookEast(){
	return east->desc;
}

string Room::lookWest(){
	return west->desc;
}

string Room::lookUp(){
	return up->desc;
}

string Room::lookDown(){
	return down->desc;
}


Room * Room::getNorthLeadsTo(){
	return (getNorth().leadsTo);
}

Room * Room::getSouthLeadsTo(){
	return (getSouth().leadsTo);
}

Room * Room::getEastLeadsTo(){
	return (getEast().leadsTo);
}

Room * Room::getWestLeadsTo(){
	return (getWest().leadsTo);
}

Room * Room::getUpLeadsTo(){
	return (getUp().leadsTo);
}

Room * Room::getDownLeadsTo(){
	return (getDown().leadsTo);
}

/*

WARNING: The below methods currently leak.  Currently working on a solution but as a work around, use this instead: 

current = *(current.getNorth().leadsTo);

*/


string Room::goNorth(Room *current){
	if (!(getNorthLeadsTo())){
		return "Cannot move there.";
	}
	*current = *(getNorthLeadsTo());
	return (*current).getDesc();
	
}

string Room::goSouth(Room *current){
	if (!(getSouthLeadsTo())){
		return "Cannot move there.";
	}
	*current = *(getSouthLeadsTo());
	return (*current).getDesc();
}

string Room::goEast(Room *current){
	if (!(getEastLeadsTo())){
		return "Cannot move there.";
	}
	*current = *(getEastLeadsTo());
	return (*current).getDesc();
}

string Room::goWest(Room *current){
	if (!(getWestLeadsTo())){
		return "Cannot move there.";
	}
	*current = *(getWestLeadsTo());
	return (*current).getDesc();
}

string Room::goUp(Room *current){
	if (!(getUpLeadsTo())){
		return "Cannot move there.";
	}
	*current = *(getUpLeadsTo());
	return (*current).getDesc();
}

string Room::goDown(Room *current){
	if (!(getDownLeadsTo())){
		return "Cannot move there.";
	}
	*current = *(getDownLeadsTo());
	return (*current).getDesc();

}


//LookAround

vector<string> Room::getDoorList(){
	vector<string> doorList;
	
	doorList.push_back(lookNorth());
	doorList.push_back(lookSouth());
	doorList.push_back(lookEast());
	doorList.push_back(lookWest());
	doorList.push_back(lookUp());
	doorList.push_back(lookDown());

	return doorList;
}


vector<string> Room::getObjList(){

	vector<string> objList;

	if (getNorthLeadsTo() != NULL){
		objList.push_back(((getNorthLeadsTo())->name));
	}

	if (getSouthLeadsTo() != NULL){
		objList.push_back(((getSouthLeadsTo())->name));
	}

	if (getEastLeadsTo() != NULL){
		objList.push_back(((getEastLeadsTo())->name));
	}

	if (getWestLeadsTo() != NULL){
		objList.push_back(((getWestLeadsTo())->name));
	}

	if (getUpLeadsTo() != NULL){
		objList.push_back(((getUpLeadsTo())->name));
	}

	if (getDownLeadsTo() != NULL){
		objList.push_back(((getDownLeadsTo())->name));
	}

	for (int i = 0; i<(getNPCs().size()); i++){
		objList.push_back(npcList.at(i)->getName());

	}
		
	return objList;
}

string Room::lookAround(){
		return getExtDesc();
	}

string Room::getObjDesc(string objName){

	vector<Room*> doorList;

	if (getNorthLeadsTo() != NULL){
		doorList.push_back(getNorthLeadsTo());
	} 

	if (getSouthLeadsTo() != NULL){
		doorList.push_back(getSouthLeadsTo());
	}

	if (getEastLeadsTo() != NULL){
		doorList.push_back(getEastLeadsTo());
	}

	if (getWestLeadsTo() != NULL){
		doorList.push_back(getWestLeadsTo());
	}

	if (getUpLeadsTo() != NULL){
		doorList.push_back(getUpLeadsTo());
	}

	if (getDownLeadsTo() != NULL){
		doorList.push_back(getDownLeadsTo());
	}


	for (int i=0; i<doorList.size(); i++){
		if ( doorList[i]->getName() == objName ){
			return doorList[i]->getDesc();
		}
	}


	for (int i=0; i<npcList.size(); i++){

		if ( npcList.at(i)->getName() == objName ){
			return npcList.at(i)->getDes();
		}
	}

	return  objName + "not found!";

}


void Room::createNPC(){
		
		NPC* monster = new NPC("monster","id:111");
		NPC* creature = new NPC("creature","id:222");

		npcList.push_back(monster);
		npcList.push_back(creature);
}




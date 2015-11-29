/*World CLASS

This is a game class that contains attributes and methods for each room contained in the game world.

Created By: Sarah Kim Dao
*/

#include "world.h"


World::World(){

	//Parsing NPCs
	shared_ptr<npcLibrary> nL( new npcLibrary());
	NPCLib = nL;

	//Parsing Rooms
	shared_ptr<roomLibrary> rL( new roomLibrary());
	roomLib = rL;

	for (auto & room :roomLib->getRoomList()){
		roomList.push_back(room);
	}

	shared_ptr<itemLibrary> iL( new itemLibrary());
	itemLib = iL;

	//Set Current Room
	currentRoom = roomList.at(0); 

	currentRoom->addNPC(NPCLib->spawn("103"));
	currentRoom->addNPC(NPCLib->spawn("104"));

	currentRoom->addItem(itemLib->spawn("103"));
	currentRoom->addItem(itemLib->spawn("104"));
}

World::~World(){
	
}

World::World(World &obj){
	currentRoom = obj.getCurrentRoom();

	for (auto & room : obj.getRoomList()){
		roomList.push_back(room);
	}
}

shared_ptr<Room> World::getCurrentRoom(){
	return currentRoom;
}


vector<shared_ptr<Room>> World::getRoomList(){
	return roomList;
}

shared_ptr<Room> World::getRoom(int i){
	return roomList.at(i);
}

shared_ptr<Room> World::getRoom(string roomID) {
	for(auto &room : roomList) {
		if(roomID.compare(room->getId()) == 0) {
			return room;
		}
	}

	return nullptr;
}

void World::setCurrentRoom(shared_ptr<Room> newRoom){
	currentRoom = newRoom;
}

void World::addReset(shared_ptr<Reset> reset) {
	resets.push_back(reset);
}

void World::performResets() {

	for(auto &reset : resets) {
		reset->performReset();
	}
}


string World::moveTo(string dir){
	for (auto & door : currentRoom->getDoorList() ) {
		if(door->findKeyword(dir) || door->getLeadsTo()->findKeyword(dir)){
			currentRoom = (door->getLeadsTo());
			return (currentRoom)->getDesc();
		}
	}
	return "Cannot go there";	
}

shared_ptr<npcLibrary> World::getNPCLib(){
	return NPCLib;
}

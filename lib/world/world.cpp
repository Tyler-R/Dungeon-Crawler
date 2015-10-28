/*World CLASS

This is a game class that contains attributes and methods for each room contained in the game world.

Created By: Sarah Kim Dao
*/

#include "world.h"


World::World(){
	shared_ptr<Room> lobby( new Room("1","Lobby","This is a lobby","The lobby is cool and clean"));
	shared_ptr<Room> bathroom( new Room("2","Bathroom","This is a bathroom","The bathroom has heated floors."));
	shared_ptr<Room> kitchen( new Room("3","Kitchen","This is a kitchen","The kitchen is sparkling."));
	shared_ptr<Room> porch( new Room("4","Porch","This is a porch","The porch is a little worn."));
	shared_ptr<Room> study( new Room("5","Study","This is a study","The study is tidy and full of books."));
	shared_ptr<Room> bedroom( new Room("6","Bedroom","This is a bedroom","The bedroom is brightly lit."));
	shared_ptr<Room> basement( new Room("7","Basement","This is a basement","The basement is dark and damp."));
	shared_ptr<Room> shower( new Room("8","Shower","This is a shower","The shower is dry."));

	lobby->addDoor("1","north", "The north door leads to the bathroom", bathroom);
	lobby->addDoor("2","south", "The south door leads to the kitchen", kitchen);
	lobby->addDoor("3","east", "The east door leads to the porch", porch);
	lobby->addDoor("4","west", "The west door leads to the study", study);
	lobby->addDoor("5","up", "The upstairs leads to the bedroom", bedroom);
	lobby->addDoor("6","down", "The downstairs leads to the basement", basement);

	bathroom->addDoor("1","south", "The south door leads to the lobby", lobby);
	kitchen->addDoor("2","north", "The north door leads to the lobby", lobby);
	porch->addDoor("3","west", "The west door leads to the lobby", lobby);
	study->addDoor("4","east", "The east door leads to the lobby", lobby);
	bedroom->addDoor("5","down", "The downstairs leads to the lobby", lobby);
	basement->addDoor("6","up", "The upstairs leads to the lobby", lobby);
	shower->addDoor("6","south", "The south leads to the bathroom", bathroom);
	bathroom->addDoor("6","north", "The north leads to the shower", shower);

	roomList.push_back(lobby);
	roomList.push_back(bathroom);
	roomList.push_back(kitchen);
	roomList.push_back(porch);
	roomList.push_back(study);
	roomList.push_back(bedroom);
	roomList.push_back(basement);

	currentRoom = lobby;
}

World::~World(){
}

World::World(World &obj){
	currentRoom = obj.getCurrentRoom();

	for (int i=0; i<obj.roomList.size(); i++){
		roomList.push_back(obj.roomList[i]);
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

void World::setCurrentRoom(shared_ptr<Room> newRoom){
	currentRoom = newRoom;
}


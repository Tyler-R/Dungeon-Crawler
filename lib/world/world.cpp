/*World CLASS

This is a game class that contains attributes and methods for each room contained in the game world.

Created By: Sarah Kim Dao
*/

#include "world.h"

World::World(){

}

World::~World(){

}

World::World(World &obj){
	//currentRoom = obj.getCurrentRoom();

	for (int i=0; i<obj.roomList.size(); i++){
		roomList.push_back(obj.roomList[i]);
	}
}

vector<Room*> World::getRoomList(){
	return roomList;
}


Room* World::getRoom(int i){
	return roomList.at(i);
}

Room* World::getCurrentRoom(){
	return currentRoom;
}

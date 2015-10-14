/*Header file for World.cpp
Created By: Sarah Kim Dao
*/
#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "room.h"

using namespace std;

class World {
	private:
		Room* currentRoom;

		vector<Room*> roomList;
	public:
		World();
		World(World &obj);

		vector<Room*> getRoomList();

		~World();

		Room* getRoom(int i);

		Room* getCurrentRoom();



};

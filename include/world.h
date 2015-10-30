/*Header file for World.cpp
Created By: Sarah Kim Dao
*/
#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <memory>

#include "room.h"
#include "reset/Reset.h"

using namespace std;

class World {
	private:
		shared_ptr<Room> currentRoom;

		vector<shared_ptr<Room>> roomList;
		vector<shared_ptr<Reset>> resets;
	public:
		World();
		World(World &obj);

		~World();

		shared_ptr<Room> getCurrentRoom();

		vector<shared_ptr<Room>>  getRoomList();

		shared_ptr<Room> getRoom(int i);
		shared_ptr<Room> getRoom(string roomID);

		void setCurrentRoom(shared_ptr<Room> newRoom);

		void addReset(shared_ptr<Reset> reset);

		void performResets();

		string moveTo(string dir);

};

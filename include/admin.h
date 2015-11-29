/*Header file for Admin.cpp
Created By: Sarah Kim Dao
*/

#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <memory>
#include <assert.h>

#include "npc.h"
#include "item.h"
#include "room.h"
#include "reset/Reset.h"
#include "world.h"

using namespace std;

class Admin {
	private:
		shared_ptr<World> world;

	public:
		void setWorld(shared_ptr<World> inputWorld);
		shared_ptr<World> getWorld(); 

		shared_ptr<Room> createRoom();
		shared_ptr<Item> createItem();
		shared_ptr<NPC> createNPC();
		shared_ptr<Door*>createDoor();
		shared_ptr<Reset> createReset();

		void modifyRoom(string id);
		void modifyItem(string id);
		void modifyNPC(string id);
		void modifyDoor(string dir);
		void modifyReset(string id);

};
/*Header file for World.cpp
Created By: Sarah Kim Dao
*/

#include <iostream>
#include <vector>
#include <string>
#include "room.h"

using namespace std;

class World {
	private:
		vector<Room*> roomList;
	public:
		World();

		vector<Room*> getRoomList();

		~World();

		Room* getRoom(int i);

};

#include <string>
#include <iostream>

#include "world.h"

using namespace std;

void panorama(Room input_room);	//looks at all doors of a room
void vicinity(Room input_room);	//looks at current location


void panorama(Room input_room){
	cout << "Look North of " << input_room.getName() << " : " << input_room.lookNorth() << endl;
	cout << "Look South of " << input_room.getName() << " : " << input_room.lookSouth() << endl;
	cout << "Look East of " << input_room.getName() << " : " << input_room.lookEast() << endl;
	cout << "Look West of " << input_room.getName() << " : " << input_room.lookWest() << endl;
	cout << "Look Up of " << input_room.getName() << " : " << input_room.lookUp() << endl;
	cout << "Look Down of " << input_room.getName() << " : " << input_room.lookDown() << endl;
}

void vicinity(Room input_room){
	cout << "Looking at Room: " << input_room.getName() << " - " << input_room.getDesc() << " - " << input_room.getExtDesc() << endl;
}

int main() {
	
	//Instantiates new World
	cout << endl << "--Instantiating New World" << endl;
	World newWorld;

	//Sets current room as starting room (index 0 in room List)
	cout << endl << "--Setting up Current Room--" << endl;
	//Room* current= newWorld.getRoom(1);
	
	cout << endl << "--Looking at Current Room--" << endl;
	cout << newWorld.getCurrentRoom()->getDesc() << endl;

	cout << endl << "--Looking at Doors of Current Room--" << endl;
	cout << newWorld.getCurrentRoom()->lookNorth() << endl;
	cout << newWorld.getCurrentRoom()->lookSouth() << endl;
	cout << newWorld.getCurrentRoom()->lookEast() << endl;
	cout << newWorld.getCurrentRoom()->lookWest() << endl;
	cout << newWorld.getCurrentRoom()->lookUp() << endl;
	cout << newWorld.getCurrentRoom()->lookDown() << endl;
	/*
	cout << endl << "--Moving North--" << endl;

	cout << newWorld.getCurrentRoom()->goNorth(newWorld.getCurrentRoom()) << endl;

	cout << endl << "--Looking at Doors of Current Room--" << endl;
	cout << newWorld.getCurrentRoom()->lookNorth() << endl;
	cout << newWorld.getCurrentRoom()->lookSouth() << endl;
	cout << newWorld.getCurrentRoom()->lookEast() << endl;
	cout << newWorld.getCurrentRoom()->lookWest() << endl;
	cout << newWorld.getCurrentRoom()->lookUp() << endl;
	cout << newWorld.getCurrentRoom()->lookDown() << endl;

	
	cout << endl << "--Moving South--" << endl;

	cout << newWorld.getCurrentRoom()->goSouth(newWorld.getCurrentRoom()) << endl;
	*/

	cout << endl << "--Getting List of Objects--" << endl;
	for(auto &str:newWorld.getCurrentRoom()->lookAroundName()){
		cout << str << endl;
	}
	

	return 0;
}


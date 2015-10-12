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
	Room* current= newWorld.getRoom(0);

	//Looks at current Room
	cout << endl << "--Looking at Current Room--" << endl;
	cout << (*current).getDesc() << endl;

	cout << endl << "--Looking at Doors of Current Room--" << endl;
	cout << (*current).lookNorth() << endl;
	cout << (*current).lookSouth() << endl;
	cout << (*current).lookEast() << endl;
	cout << (*current).lookWest() << endl;
	cout << (*current).lookUp() << endl;
	cout << (*current).lookDown() << endl;


	cout << endl << "--Moving North--" << endl;
	//Non-Leaking Method to move North
	//current = ((*current).getNorthLeadsTo());

	//Leaking Method to move North
	(*current).goNorth(current);

	cout << endl << "--Looking at Current Room--" << endl;
	//Looks at current Room after moving north.
	cout << (*current).getDesc() << endl;

	cout << endl << "--Looking at Doors of Current Room--" << endl;
	cout << (*current).lookNorth() << endl;
	cout << (*current).lookSouth() << endl;
	cout << (*current).lookEast() << endl;
	cout << (*current).lookWest() << endl;
	cout << (*current).lookUp() << endl;
	cout << (*current).lookDown() << endl;

	cout << endl << "--End Test--" << endl;

	return 0;
}


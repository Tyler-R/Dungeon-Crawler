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

	cout << endl << "--Setting up Current Room--" << endl;
	
	cout << endl << "--Looking at Current Room--" << endl;
	cout << newWorld.getCurrentRoom()->getDesc() << endl;

	cout << endl << "--Getting a Good Look at the Room--" << endl;
	cout << newWorld.getCurrentRoom()->lookAround()  << endl;

	cout << endl << "--Looking at Doors of Current Room--" << endl;
	cout << newWorld.getCurrentRoom()->lookNorth() << endl;
	cout << newWorld.getCurrentRoom()->lookSouth() << endl;
	cout << newWorld.getCurrentRoom()->lookEast() << endl;
	cout << newWorld.getCurrentRoom()->lookWest() << endl;
	cout << newWorld.getCurrentRoom()->lookUp() << endl;
	cout << newWorld.getCurrentRoom()->lookDown() << endl;


	

	cout << endl << "--Getting List of Objects--" << endl;
	for(auto &str:newWorld.getCurrentRoom()->getObjList()){
		cout << str << endl;
	}

	cout << endl << "--Looking for a Weaponsmith--" << endl;
	cout << newWorld.getCurrentRoom()->getObjDesc("weaponsmith") << endl;

	cout << endl << "--Looking for a Study--" << endl;
	cout << newWorld.getCurrentRoom()->getObjDesc("Study") << endl;
	
	cout << endl << "--Moving North--" << endl;

	cout << newWorld.getCurrentRoom()->goNorth(newWorld.getCurrentRoom()) << endl;

	cout << endl << "--Looking at Doors of Current Room--" << endl;
	cout << newWorld.getCurrentRoom()->lookNorth() << endl;
	cout << newWorld.getCurrentRoom()->lookSouth() << endl;
	cout << newWorld.getCurrentRoom()->lookEast() << endl;
	cout << newWorld.getCurrentRoom()->lookWest() << endl;
	cout << newWorld.getCurrentRoom()->lookUp() << endl;
	cout << newWorld.getCurrentRoom()->lookDown() << endl;

	cout << endl << "--Getting List of Objects--" << endl;
	for(auto &str:newWorld.getCurrentRoom()->getObjList()){
		cout << str << endl;
	}

	
	cout << endl << "--Moving South--" << endl;

	cout << newWorld.getCurrentRoom()->goSouth(newWorld.getCurrentRoom()) << endl;

	cout << endl << "--Moving North--" << endl;

	cout << newWorld.getCurrentRoom()->goNorth(newWorld.getCurrentRoom()) << endl;

	cout << endl << "--Moving East--" << endl;

	cout << newWorld.getCurrentRoom()->goEast(newWorld.getCurrentRoom()) << endl;

	cout << endl << "--Moving North--" << endl;

	cout << newWorld.getCurrentRoom()->goNorth(newWorld.getCurrentRoom()) << endl;

	cout << endl << "--Getting a Good Look at the Room--" << endl;
	cout << newWorld.getCurrentRoom()->lookAround()  << endl;

	cout << endl << "--Looking at Doors of Current Room--" << endl;
	cout << newWorld.getCurrentRoom()->lookNorth() << endl;
	cout << newWorld.getCurrentRoom()->lookSouth() << endl;
	cout << newWorld.getCurrentRoom()->lookEast() << endl;
	cout << newWorld.getCurrentRoom()->lookWest() << endl;
	cout << newWorld.getCurrentRoom()->lookUp() << endl;
	cout << newWorld.getCurrentRoom()->lookDown() << endl;

	cout << endl << "--Getting List of Objects--" << endl;
	for(auto &str:newWorld.getCurrentRoom()->getObjList()){
		cout << str << endl;
	}

	cout << endl << "--Moving West--" << endl;

	cout << newWorld.getCurrentRoom()->goWest(newWorld.getCurrentRoom()) << endl;

	cout << endl << "--Looking at Doors of Current Room--" << endl;
	cout << newWorld.getCurrentRoom()->lookNorth() << endl;
	cout << newWorld.getCurrentRoom()->lookSouth() << endl;
	cout << newWorld.getCurrentRoom()->lookEast() << endl;
	cout << newWorld.getCurrentRoom()->lookWest() << endl;
	cout << newWorld.getCurrentRoom()->lookUp() << endl;
	cout << newWorld.getCurrentRoom()->lookDown() << endl;


	
	cout << endl << "--Getting List of Objects--" << endl;
	for(auto &str:newWorld.getCurrentRoom()->getObjList()){
		cout << str << endl;
	}

	cout << endl << "--Getting List of Doors--" << endl;
	for(auto &str:newWorld.getCurrentRoom()->getDoorList()){
		cout << str << endl;
	}

	cout << endl << "--Getting a Good Look at the Room--" << endl;
	cout << newWorld.getCurrentRoom()->lookAround()  << endl;

	cout << endl << "--Moving South--" << endl;

	cout << newWorld.getCurrentRoom()->goSouth(newWorld.getCurrentRoom()) << endl;

	cout << endl << "--Looking at Doors of Current Room--" << endl;
	cout << newWorld.getCurrentRoom()->lookNorth() << endl;
	cout << newWorld.getCurrentRoom()->lookSouth() << endl;
	cout << newWorld.getCurrentRoom()->lookEast() << endl;
	cout << newWorld.getCurrentRoom()->lookWest() << endl;
	cout << newWorld.getCurrentRoom()->lookUp() << endl;
	cout << newWorld.getCurrentRoom()->lookDown() << endl;

	cout << endl << "--Moving South--" << endl;

	cout << newWorld.getCurrentRoom()->goSouth(newWorld.getCurrentRoom()) << endl;

	cout << endl << "--Looking at Doors of Current Room--" << endl;
	cout << newWorld.getCurrentRoom()->lookNorth() << endl;
	cout << newWorld.getCurrentRoom()->lookSouth() << endl;
	cout << newWorld.getCurrentRoom()->lookEast() << endl;
	cout << newWorld.getCurrentRoom()->lookWest() << endl;
	cout << newWorld.getCurrentRoom()->lookUp() << endl;
	cout << newWorld.getCurrentRoom()->lookDown() << endl;

	cout << endl << "--Getting List of Objects--" << endl;
	for(auto &str:newWorld.getCurrentRoom()->getObjList()){
		cout << str << endl;
	}

	cout << endl << "--Moving East--" << endl;

	cout << newWorld.getCurrentRoom()->goEast(newWorld.getCurrentRoom()) << endl;

	cout << endl << "--Looking at Doors of Current Room--" << endl;
	cout << newWorld.getCurrentRoom()->lookNorth() << endl;
	cout << newWorld.getCurrentRoom()->lookSouth() << endl;
	cout << newWorld.getCurrentRoom()->lookEast() << endl;
	cout << newWorld.getCurrentRoom()->lookWest() << endl;
	cout << newWorld.getCurrentRoom()->lookUp() << endl;
	cout << newWorld.getCurrentRoom()->lookDown() << endl;
	
	cout << endl << "--Moving West--" << endl;

	cout << newWorld.getCurrentRoom()->goWest(newWorld.getCurrentRoom()) << endl;

	cout << endl << "--Looking at Doors of Current Room--" << endl;
	cout << newWorld.getCurrentRoom()->lookNorth() << endl;
	cout << newWorld.getCurrentRoom()->lookSouth() << endl;
	cout << newWorld.getCurrentRoom()->lookEast() << endl;
	cout << newWorld.getCurrentRoom()->lookWest() << endl;
	cout << newWorld.getCurrentRoom()->lookUp() << endl;
	cout << newWorld.getCurrentRoom()->lookDown() << endl;

	cout << endl << "--Getting List of Objects--" << endl;
	for(auto &str:newWorld.getCurrentRoom()->getObjList()){
		cout << str << endl;
	}

	cout << endl << "--Moving West--" << endl;

	cout << newWorld.getCurrentRoom()->goWest(newWorld.getCurrentRoom()) << endl;

	cout << endl << "--Looking at Doors of Current Room--" << endl;
	cout << newWorld.getCurrentRoom()->lookNorth() << endl;
	cout << newWorld.getCurrentRoom()->lookSouth() << endl;
	cout << newWorld.getCurrentRoom()->lookEast() << endl;
	cout << newWorld.getCurrentRoom()->lookWest() << endl;
	cout << newWorld.getCurrentRoom()->lookUp() << endl;
	cout << newWorld.getCurrentRoom()->lookDown() << endl;

	cout << endl << "--Moving East--" << endl;

	cout << newWorld.getCurrentRoom()->goEast(newWorld.getCurrentRoom()) << endl;

	cout << endl << "--Looking at Doors of Current Room--" << endl;
	cout << newWorld.getCurrentRoom()->lookNorth() << endl;
	cout << newWorld.getCurrentRoom()->lookSouth() << endl;
	cout << newWorld.getCurrentRoom()->lookEast() << endl;
	cout << newWorld.getCurrentRoom()->lookWest() << endl;
	cout << newWorld.getCurrentRoom()->lookUp() << endl;
	cout << newWorld.getCurrentRoom()->lookDown() << endl;

	cout << endl << "--Getting List of Objects--" << endl;
	for(auto &str:newWorld.getCurrentRoom()->getObjList()){
		cout << str << endl;
	}

	cout << endl << "--Moving South--" << endl;

	cout << newWorld.getCurrentRoom()->goSouth(newWorld.getCurrentRoom()) << endl;

	cout << endl << "--Looking at Doors of Current Room--" << endl;
	cout << newWorld.getCurrentRoom()->lookNorth() << endl;
	cout << newWorld.getCurrentRoom()->lookSouth() << endl;
	cout << newWorld.getCurrentRoom()->lookEast() << endl;
	cout << newWorld.getCurrentRoom()->lookWest() << endl;
	cout << newWorld.getCurrentRoom()->lookUp() << endl;
	cout << newWorld.getCurrentRoom()->lookDown() << endl;

	cout << endl << "--Getting List of Objects--" << endl;
	for(auto &str:newWorld.getCurrentRoom()->getObjList()){
		cout << str << endl;
	}

	cout << endl << "--Moving North--" << endl;

	cout << newWorld.getCurrentRoom()->goNorth(newWorld.getCurrentRoom()) << endl;

	cout << endl << "--Looking at Doors of Current Room--" << endl;
	cout << newWorld.getCurrentRoom()->lookNorth() << endl;
	cout << newWorld.getCurrentRoom()->lookSouth() << endl;
	cout << newWorld.getCurrentRoom()->lookEast() << endl;
	cout << newWorld.getCurrentRoom()->lookWest() << endl;
	cout << newWorld.getCurrentRoom()->lookUp() << endl;
	cout << newWorld.getCurrentRoom()->lookDown() << endl;

	cout << endl << "--Getting List of Objects--" << endl;
	for(auto &str:newWorld.getCurrentRoom()->getObjList()){
		cout << str << endl;
	}

	cout << endl << "--Moving Up--" << endl;

	cout << newWorld.getCurrentRoom()->goUp(newWorld.getCurrentRoom()) << endl;

	cout << endl << "--Looking at Doors of Current Room--" << endl;
	cout << newWorld.getCurrentRoom()->lookNorth() << endl;
	cout << newWorld.getCurrentRoom()->lookSouth() << endl;
	cout << newWorld.getCurrentRoom()->lookEast() << endl;
	cout << newWorld.getCurrentRoom()->lookWest() << endl;
	cout << newWorld.getCurrentRoom()->lookUp() << endl;
	cout << newWorld.getCurrentRoom()->lookDown() << endl;

	cout << endl << "--Getting List of Objects--" << endl;
	for(auto &str:newWorld.getCurrentRoom()->getObjList()){
		cout << str << endl;
	}

	cout << endl << "--Moving Down--" << endl;

	cout << newWorld.getCurrentRoom()->goDown(newWorld.getCurrentRoom()) << endl;

	cout << endl << "--Looking at Doors of Current Room--" << endl;
	cout << newWorld.getCurrentRoom()->lookNorth() << endl;
	cout << newWorld.getCurrentRoom()->lookSouth() << endl;
	cout << newWorld.getCurrentRoom()->lookEast() << endl;
	cout << newWorld.getCurrentRoom()->lookWest() << endl;
	cout << newWorld.getCurrentRoom()->lookUp() << endl;
	cout << newWorld.getCurrentRoom()->lookDown() << endl;

	cout << endl << "--Getting List of Objects--" << endl;
	for(auto &str:newWorld.getCurrentRoom()->getObjList()){
		cout << str << endl;
	}

	cout << endl << "--Moving Down--" << endl;

	cout << newWorld.getCurrentRoom()->goDown(newWorld.getCurrentRoom()) << endl;

	cout << endl << "--Looking at Doors of Current Room--" << endl;
	cout << newWorld.getCurrentRoom()->lookNorth() << endl;
	cout << newWorld.getCurrentRoom()->lookSouth() << endl;
	cout << newWorld.getCurrentRoom()->lookEast() << endl;
	cout << newWorld.getCurrentRoom()->lookWest() << endl;
	cout << newWorld.getCurrentRoom()->lookUp() << endl;
	cout << newWorld.getCurrentRoom()->lookDown() << endl;

	cout << endl << "--Getting List of Objects--" << endl;
	for(auto &str:newWorld.getCurrentRoom()->getObjList()){
		cout << str << endl;
	}

	cout << endl << "--Moving Up--" << endl;

	cout << newWorld.getCurrentRoom()->goUp(newWorld.getCurrentRoom()) << endl;

	cout << endl << "--Looking at Doors of Current Room--" << endl;
	cout << newWorld.getCurrentRoom()->lookNorth() << endl;
	cout << newWorld.getCurrentRoom()->lookSouth() << endl;
	cout << newWorld.getCurrentRoom()->lookEast() << endl;
	cout << newWorld.getCurrentRoom()->lookWest() << endl;
	cout << newWorld.getCurrentRoom()->lookUp() << endl;
	cout << newWorld.getCurrentRoom()->lookDown() << endl;

	cout << endl << "--Getting List of Objects--" << endl;
	for(auto &str:newWorld.getCurrentRoom()->getObjList()){
		cout << str << endl;
	}

	
	cout << endl << "--EndTest--" << endl;
	return 0;
}


#include <string>
#include <iostream>
#include "room.h"

using namespace std;

void panorama(Room input_room);	//looks at all doors of a room
void vicinity(Room input_room);	//looks at current location

void panorama(Room input_room){
	cout << "-- Checking doors of " << input_room.getName() << "--"  << endl;
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

	cout << endl<< "---This is a Test Module for the Room Class and Door Class---" << endl;

	cout << endl << "---Now testing the Default Constructor---" << endl << endl;

	Room room_100;
	cout << "room_100 created." << endl;
	vicinity(room_100);

	cout << endl << "---Now adding name, description and extended description to room_100---" << endl << endl;
	room_100.setName("Bathroom");
	vicinity(room_100);
	room_100.setDesc("This is a bathroom");
	vicinity(room_100);
	room_100.setExtDesc("The bathroom has heated floors.");
	vicinity(room_100);

	cout << endl << "---Now testing room_100's doors---" << endl << endl;
	panorama(room_100);




	cout << endl << "---Now testing the Constructor with Parameters---" << endl << endl;

	Room room_101("Lobby","This is a lobby","The lobby is cool and clean");
	cout << "room_101 created. This room will be a lobby." << endl;
	vicinity(room_101);

	cout << endl << "---Now testing room_101's doors---" << endl << endl;
	panorama(room_101);

	cout << endl << "---Now connecting lobby to bathroom---" << endl << endl;

	cout << "---The lobby's north door will connect to the bathroom's south door---" << endl << endl;

	room_101.setNorth(&room_100, "The north door leads to the bathroom");
	panorama(room_101);

	cout << endl;

	room_100.setSouth(&room_101, "The south door leads back the lobby");
	panorama(room_100);

	cout << endl << "---Now testing the Copy Constructor---" << endl << endl;

	cout << "Now copying Room 100" << endl << endl;

	Room room_100copy(room_100);
	vicinity(room_100copy);
	cout << endl;
	panorama(room_100copy);

	cout << endl << "---Now testing navigation---" << endl << endl;

	Room current = room_101;

	vicinity(current);
	panorama(current);
	
	current = *(current.getNorthLeadsTo());

	cout << endl << "---Checking current room---" << endl << endl;

	cout << endl <<  "---Moving North---" << endl << endl;

	vicinity(current);
	panorama(current);


	//cout << endl << "---End of Test---" << endl << endl;
	return 0;
}

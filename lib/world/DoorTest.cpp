#include <string>
#include <iostream>

#include "room.h"

class Room;

using namespace std;

int main() {

	cout << endl << "Creating Rooms" << endl;

	Room lobby("1","Lobby","This is a lobby","The lobby is cool and clean");
	Room bathroom("2","Bathroom","This is a bathroom","The bathroom has heated floors.");
	Room kitchen("3","Kitchen","This is a kitchen","The kitchen is sparkling.");
	Room porch("4","Porch","This is a porch","The porch is a little worn.");
	Room study("5","Study","This is a study","The study is tidy and full of books.");
	Room bedroom("6","Bedroom","This is a bedroom","The bedroom is brightly lit.");
	Room basement("7","Basement","This is a basement","The basement is dark and damp.");
	Room shower("8","Shower","This is a shower","The shower is dry.");

	cout << endl << "Creating Doors" << endl;

	lobby.addDoor("1","north", "The north door leads to the bathroom", bathroom);
	lobby.addDoor("2","south", "The south door leads to the kitchen", kitchen);
	lobby.addDoor("3","east", "The east door leads to the porch", porch);
	lobby.addDoor("4","west", "The west door leads to the study", study);
	lobby.addDoor("5","up", "The upstairs leads to the bedroom", bedroom);
	lobby.addDoor("6","down", "The downstairs leads to the basement", basement);
	bathroom.addDoor("7","north", "The north door leads to the shower", shower);

	for (auto & doorDesc : lobby.getDoorDescList()) {
	    cout << endl << doorDesc << endl;
	}

	for (auto & objName : lobby.getObjList()) {
	    cout << endl << objName << endl;
	}



	/*
	Door current();
	Door center("0","Center","This is the center door",bathroom);
	Door north("1","North","This is the north door",bathroom);
	Door south("2","South","This is the south door",bathroom);
	Door east("3","East","This is the east door",bathroom);
	Door west("4","West","This is the west door",bathroom);

	cout << "Setting up door's leadTos" << endl;
	north.setLeadsTo(bathroom);

	cout << endl << bathroom.getName() << endl;
	cout << endl << north.getLeadsTo()->getDesc() << endl;
	

	cout << "Adding keywords to the center door" << endl;
	center.addKeyword("Middle");
	center.addKeyword("Nexus");
	center.addKeyword("Central");
	center.printKeywords();

	cout << endl << "Keyword Central is " << center.findKeyword("Central") << endl;
	cout << endl << "Keyword Windy is " << center.findKeyword("Windy") << endl;


	cout << endl << "Keyword Central is " << center.findKeyword("Central") << endl;
	cout << endl << "Keyword Windy is " << center.findKeyword("Windy") << endl;

*/
}


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

	lobby.addDoor("north", "The north door leads to the bathroom", bathroom);

	
	Door current();
	Door center("Center","This is the center door");
	Door north("North","This is the north door");
	Door south("South","This is the south door");
	Door east("East","This is the east door");
	Door west("West","This is the west door");

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
}

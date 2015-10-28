#include <string>
#include <iostream>

#include "room.h"

class Room;

using namespace std;

int main() {

	cout << endl << "---Creating Rooms---" << endl;

	shared_ptr<Room> lobby( new Room("1","Lobby","This is a lobby","The lobby is cool and clean"));
	
	shared_ptr<Room> bathroom( new Room("2","Bathroom","This is a bathroom","The bathroom has heated floors."));
	shared_ptr<Room> kitchen( new Room("3","Kitchen","This is a kitchen","The kitchen is sparkling."));
	shared_ptr<Room> porch( new Room("4","Porch","This is a porch","The porch is a little worn."));
	shared_ptr<Room> study( new Room("5","Study","This is a study","The study is tidy and full of books."));
	shared_ptr<Room> bedroom( new Room("6","Bedroom","This is a bedroom","The bedroom is brightly lit."));
	shared_ptr<Room> basement( new Room("7","Basement","This is a basement","The basement is dark and damp."));
	shared_ptr<Room> shower( new Room("8","Shower","This is a shower","The shower is dry."));

	cout << endl << endl << "---Creating Doors---" << endl;

	lobby->addDoor("1","north", "The north door leads to the bathroom", bathroom);
	lobby->addDoor("2","south", "The south door leads to the kitchen", kitchen);
	lobby->addDoor("3","east", "The east door leads to the porch", porch);
	lobby->addDoor("4","west", "The west door leads to the study", study);
	lobby->addDoor("5","up", "The upstairs leads to the bedroom", bedroom);
	lobby->addDoor("6","down", "The downstairs leads to the basement", basement);

	bathroom->addDoor("1","south", "The south door leads to the lobby", lobby);
	kitchen->addDoor("2","north", "The north door leads to the lobby", lobby);
	porch->addDoor("3","west", "The west door leads to the lobby", lobby);
	study->addDoor("4","east", "The east door leads to the lobby", lobby);
	bedroom->addDoor("5","down", "The downstairs leads to the lobby", lobby);
	basement->addDoor("6","up", "The upstairs leads to the lobby", lobby);
	shower->addDoor("6","south", "The south leads to the bathroom", bathroom);
	bathroom->addDoor("6","north", "The north leads to the shower", shower);
	
	//bathroom->addDoor("7","north", "The north door leads to the shower", shower);
	cout <<endl << endl << "---Setting current location as Lobby---" << endl;

	auto currentLoc = lobby;
	cout << endl << currentLoc->getName() << endl;

	cout << endl << endl << "---Getting Description of Doors in Current Location---" << endl;
	for (auto & doorDesc : currentLoc->getDoorDescList()) {
	    cout << endl << doorDesc << endl;
	}

	
	cout <<endl << endl << "---Getting List of Objects in Current Location---" << endl;
	for (auto & objName : currentLoc->getObjList()) {
	    cout << endl << objName << endl;
	}
	
	cout <<endl << endl << "---Looking Around Current Location---" << endl;
		cout << endl << currentLoc->lookAround() << endl;

	cout <<endl << endl << "---Printing Current Location Keywords---" << endl;
		currentLoc->printKeywords();

	cout <<endl << endl << "---Adding new KeyWord to Current Location---" << endl;
		currentLoc->addKeyword("Foyer");
		currentLoc->addKeyword("Vestibule");
	
	cout <<endl << endl << "---Printing  Keywords---" << endl;
		currentLoc->printKeywords();

	cout <<endl << endl << "---Searching for Current Location Keyword 'Vestibule'---" << endl;
	if(currentLoc->findKeyword("Vestibule")){
		cout << endl << "Match Found!" << endl;
	}
	else{
		cout << endl << "Match NOT Found!" << endl;	
	}
	
	cout <<endl << endl << "---Searching for Current Location Keyword 'vestibule'---" << endl;
	if(currentLoc->findKeyword("vestibule")){
		cout << endl << "Match Found!" << endl;
	}
	else{
		cout << endl << "Match NOT Found!" << endl;	
	}

	cout <<endl << endl << "---Searching for Current Location Keyword 'caboose'---" << endl;
	if(currentLoc->findKeyword("caboose")){
		cout << endl << "Match Found!" << endl;
	}
	else{
		cout << endl << "Match NOT Found!" << endl;	
	}


	cout <<endl << endl << "---Looking for Bathroom of Current Location---" << endl;
	cout << endl << currentLoc->lookAt("Bathroom") << endl;

	cout <<endl << endl << "---Looking North of Current Location---" << endl;
	cout << endl << currentLoc->lookAt("north") << endl;

	cout <<endl << endl << "---Looking Down of Current Location---" << endl;
	cout << endl << currentLoc->lookAt("down") << endl;

	cout <<endl << endl << "---Looking Down of Current Location---" << endl;
	cout << endl << currentLoc->lookAt("down") << endl;

	cout << endl << "---Moving North from current location---" << endl;

	cout << currentLoc->moveTo("north", currentLoc) << endl; 

	cout <<endl << endl << "---Looking Around Current Location---" << endl;
		cout << endl << currentLoc->lookAround() << endl;

	cout << endl << endl << "---Getting Description of Doors in Current Location---" << endl;
	for (auto & doorDesc : currentLoc->getDoorDescList()) {
	    cout << endl << doorDesc << endl;
	}

	
	cout <<endl << endl << "---Getting List of Objects in Current Location---" << endl;
	for (auto & objName : currentLoc->getObjList()) {
	    cout << endl << objName << endl;
	}
	
	cout <<endl << endl << "---Looking Around Current Location---" << endl;
		cout << endl << currentLoc->lookAround() << endl;

	cout <<endl << endl << "---Printing Current Location Keywords---" << endl;
		currentLoc->printKeywords();

	cout <<endl << endl << "---Adding new KeyWord to Current Location---" << endl;
		currentLoc->addKeyword("Washroom");
		currentLoc->addKeyword("Water Closet");
	
	cout <<endl << endl << "---Printing  Keywords---" << endl;
		currentLoc->printKeywords();

	cout << endl << "---Moving to shower from current location---" << endl;

	cout << currentLoc->moveTo("shower", currentLoc) << endl; 

	cout << endl << "---Moving to 'Water Closet' from current location---" << endl;

	cout << currentLoc->moveTo("Washroom", currentLoc) << endl; 


	cout <<endl << endl << "---Ending Test---" << endl << endl;
	
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


#include <string>
#include <iostream>

#include "world.h"

using namespace std;

int main() {
	
	cout << "hello world!" << endl;

	World newWorld;

	cout << endl << "--Setting up Current Room--" << endl;
	
	cout << endl << "--Looking at Current Room--" << endl;
	cout << newWorld.getCurrentRoom()->getDesc() << endl;

	cout << endl << "--Getting a Good Look at the Room--" << endl;
	cout << newWorld.getCurrentRoom()->lookAround()  << endl;

	cout << endl << "--Getting List of Objects--" << endl;

	for (auto & door : newWorld.getCurrentRoom()->getDoorDescList()) {
	    cout << door << endl;
	}

	cout << endl << "--Getting List of Doors--" << endl;

	for (auto & door : newWorld.getCurrentRoom()->getObjList()) {
	    cout << door << endl;
	}

	cout << endl << "--Printing Keywords--" << endl;

	newWorld.getCurrentRoom()->printKeywords();

	cout << endl << "--Adding New Keywords to Lobby--" << endl;
	newWorld.getCurrentRoom()->addKeyword("Foyer");
	newWorld.getCurrentRoom()->addKeyword("Entrance Hall");
	newWorld.getCurrentRoom()->addKeyword("Vestibule");

	newWorld.getCurrentRoom()->printKeywords();

	cout << endl << "--Testing Lobby's Keywords--" << endl;
	cout << endl << "--Looking at 'Lobby'--" << endl;
	cout << newWorld.getCurrentRoom()->lookAt("Lobby") << endl;

	cout << endl << "--Looking at 'Foyer'--" << endl;
	cout << newWorld.getCurrentRoom()->lookAt("Foyer") << endl;

	cout << endl << "--Looking at 'vestibule'--" << endl;
	cout << newWorld.getCurrentRoom()->lookAt("vestibule") << endl;

	cout << endl << "--Looking at 'caboose'--" << endl;
	cout << newWorld.getCurrentRoom()->lookAt("caboose") << endl;

	cout << endl << "--Moving to Bathroom--" << endl;

	cout << newWorld.moveTo("north") << endl;	

	cout << endl << "--Looking at Current Room--" << endl;
	cout << newWorld.getCurrentRoom()->getDesc() << endl;

	cout << endl << "--Getting a Good Look at the Room--" << endl;
	cout << newWorld.getCurrentRoom()->lookAround()  << endl;

	cout << endl << "--Getting List of Objects--" << endl;

	for (auto & door : newWorld.getCurrentRoom()->getDoorDescList()) {
	    cout << door << endl;
	}

	cout << endl << "--Getting List of Doors--" << endl;

	for (auto & door : newWorld.getCurrentRoom()->getObjList()) {
	    cout << door << endl;
	}

	cout << endl << "--Adding New Keywords to Bathroom--" << endl;
	newWorld.getCurrentRoom()->addKeyword("Washroom");
	newWorld.getCurrentRoom()->addKeyword("Restroom");
	newWorld.getCurrentRoom()->addKeyword("Powder Room");

	newWorld.getCurrentRoom()->printKeywords();


	cout << endl << "--Moving to Shower--" << endl;

	cout << newWorld.moveTo("shower") << endl;	

	cout << endl << "--Looking at Current Room--" << endl;
	cout << newWorld.getCurrentRoom()->getDesc() << endl;

	cout << endl << "--Getting a Good Look at the Room--" << endl;
	cout << newWorld.getCurrentRoom()->lookAround()  << endl;

	cout << endl << "--Getting List of Objects--" << endl;

	for (auto & door : newWorld.getCurrentRoom()->getDoorDescList()) {
	    cout << door << endl;
	}

	cout << endl << "--Getting List of Doors--" << endl;

	for (auto & door : newWorld.getCurrentRoom()->getObjList()) {
	    cout << door << endl;
	}

	cout << endl << "--Moving to 'Powder Room'--" << endl;

	cout << newWorld.moveTo("powder room") << endl;	

	cout << endl << "--Looking at Current Room--" << endl;
	cout << newWorld.getCurrentRoom()->getDesc() << endl;

	cout << endl << "--Getting a Good Look at the Room--" << endl;
	cout << newWorld.getCurrentRoom()->lookAround()  << endl;

	cout << endl << "--Getting List of Objects--" << endl;

	for (auto & door : newWorld.getCurrentRoom()->getDoorDescList()) {
	    cout << door << endl;
	}

	cout << endl << "--Getting List of Doors--" << endl;

	for (auto & door : newWorld.getCurrentRoom()->getObjList()) {
	    cout << door << endl;
	}











	cout << endl << "--EndTest--" << endl;
}

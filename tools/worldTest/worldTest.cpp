#include <string>
#include <iostream>

#include "world.h"

using namespace std;

int main() {
	
	cout << "--Welcome to the worldTest module.--" << endl;

	cout << endl << "--Now instantiating the World--" << endl;
	World newWorld;
	
	cout << endl << "--Now testing interaction with Current Room--" << endl;	

	cout << endl << "--Looking at Current Room--" << endl;
	cout << newWorld.getCurrentRoom()->getDesc() << endl;

	cout << endl << "--Getting a Good Look Around the Room--" << endl;
	cout << newWorld.getCurrentRoom()->lookAround()  << endl;

	cout << endl << "--Looking at Exits--" << endl;

	for (auto & door : newWorld.getCurrentRoom()->getDoorDescList()) {
	    cout << door << endl;
	}

	cout << endl << "--Getting List of Objects--" << endl;

	for (auto & door : newWorld.getCurrentRoom()->getObjList()) {
	    cout << door << endl;
	}

	cout << endl << "--Printing Keywords of Current Room--" << endl;

	newWorld.getCurrentRoom()->printKeywords();

	cout << endl << "--Adding New Keywords to Room--" << endl;
	newWorld.getCurrentRoom()->addKeyword("Foyer");
	newWorld.getCurrentRoom()->addKeyword("Entrance Hall");
	newWorld.getCurrentRoom()->addKeyword("Vestibule");

	newWorld.getCurrentRoom()->printKeywords();

	cout << endl << "--Now using Lobby's Keywords to look at the Lobby--" << endl;
	
	cout << endl << "--Looking at 'Lobby'--" << endl;
	cout << newWorld.getCurrentRoom()->lookAt("Lobby") << endl;

	cout << endl << "--Looking at 'Foyer'--" << endl;
	cout << newWorld.getCurrentRoom()->lookAt("Foyer") << endl;

	cout << endl << "--Looking at 'vestibule'--" << endl;
	cout << newWorld.getCurrentRoom()->lookAt("vestibule") << endl;

	cout << endl << "--Now using an invalid Keyword to look at the Lobby--" << endl;

	cout << endl << "--Looking at 'caboose'--" << endl;
	cout << newWorld.getCurrentRoom()->lookAt("caboose") << endl;

	cout << endl << "----" << endl;	
	cout << endl << "----" << endl;	

	cout << endl << "--Now testing moving to different rooms--" << endl;

	cout << endl << "--From the Lobby, we move 'north'--" << endl;

	cout << newWorld.moveTo("north") << endl;	

	cout << endl << "--Looking at Current Room--" << endl;
	cout << newWorld.getCurrentRoom()->getDesc() << endl;

	cout << endl << "--Getting a Good Look at the Room--" << endl;
	cout << newWorld.getCurrentRoom()->lookAround()  << endl;

	for (auto & door : newWorld.getCurrentRoom()->getDoorDescList()) {
	    cout << door << endl;
	}

	cout << endl << "--Getting List of Objects in the Room--" << endl;

	for (auto & door : newWorld.getCurrentRoom()->getObjList()) {
	    cout << door << endl;
	}

	vector<string> bathroomKeywords;

	bathroomKeywords.push_back("Washroom");
	bathroomKeywords.push_back("Restroom");
	bathroomKeywords.push_back("Powder Room");

	cout << endl << "--Adding New Keywords to Bathroom--" << endl;
	newWorld.getCurrentRoom()->addKeywords(bathroomKeywords);

	newWorld.getCurrentRoom()->printKeywords();

	cout << endl << "--Moving to 'shower'--" << endl;

	cout << newWorld.moveTo("shower") << endl;	

	cout << endl << "--Looking at Current Room--" << endl;
	cout << newWorld.getCurrentRoom()->getDesc() << endl;

	cout << endl << "--Getting a Good Look at the Room--" << endl;
	cout << newWorld.getCurrentRoom()->lookAround()  << endl;

	cout << endl << "--Looking at Exits--" << endl;

	for (auto & door : newWorld.getCurrentRoom()->getDoorDescList()) {
	    cout << door << endl;
	}

	cout << endl << "--Getting List of Objects--" << endl;

	for (auto & door : newWorld.getCurrentRoom()->getObjList()) {
	    cout << door << endl;
	}

	cout << endl << "--Moving to 'Powder Room'--" << endl;

	cout << newWorld.moveTo("powder room") << endl;	

	cout << endl << "--Looking at Current Room--" << endl;
	cout << newWorld.getCurrentRoom()->getDesc() << endl;

	cout << endl << "--Looking at Exits--" << endl;

	for (auto & door : newWorld.getCurrentRoom()->getDoorDescList()) {
	    cout << door << endl;
	}

	cout << endl << "--Getting List of Objects--" << endl;

	for (auto & door : newWorld.getCurrentRoom()->getObjList()) {
	    cout << door << endl;
	}

	cout << endl << "--Moving to 'east' (an invalid location)--" << endl;

	cout << newWorld.moveTo("east") << endl;	

	cout << endl << "--Moving to 'library' (an invalid location)--" << endl;

	cout << newWorld.moveTo("library") << endl;	

	cout << endl << "--Moving to 'foyer'--" << endl;

	cout << newWorld.moveTo("foyer") << endl;	

	cout << endl << "--Looking at Current Room--" << endl;
	cout << newWorld.getCurrentRoom()->getDesc() << endl;

	cout << endl << "--Getting a Good Look at the Room--" << endl;
	cout << newWorld.getCurrentRoom()->lookAround()  << endl;

	cout << endl << "--Looking at Exits--" << endl;

	for (auto & door : newWorld.getCurrentRoom()->getDoorDescList()) {
	    cout << door << endl;
	}

	cout << endl << "--Getting List of Objects--" << endl;

	for (auto & door : newWorld.getCurrentRoom()->getObjList()) {
	    cout << door << endl;
	}

	cout << endl << "----" << endl;	
	cout << endl << "----" << endl;	

	cout << endl << "--Now testing NPC interaction--" << endl;	

	cout << endl << "--Getting List of Objects--" << endl;

	for (auto & door : newWorld.getCurrentRoom()->getObjList()) {
	    cout << door << endl;
	}

	cout << endl << "--Looking at NPCs--" << endl;

	cout << endl << "--Looking at 'butler'--" << endl;
	cout << endl << newWorld.getCurrentRoom()->lookAt("butler") << endl;	

	cout << endl << "--Looking at 'knight'--" << endl;
	cout << endl << newWorld.getCurrentRoom()->lookAt("knight") << endl;	

	cout << endl << "--Using Keywords to look at NPCs--" << endl;

	cout << endl << "--Looking at 'servant'--" << endl;
	cout << endl << newWorld.getCurrentRoom()->lookAt("servant") << endl;	

	cout << endl << "--Looking at 'swordsman'--" << endl;
	cout << endl << newWorld.getCurrentRoom()->lookAt("swordsman") << endl;	

	cout << endl << "--EndTest--" << endl;
}

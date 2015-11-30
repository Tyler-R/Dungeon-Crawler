#include <string>
#include <iostream>
#include <memory>
#include "world.h"
#include "user.h"


using namespace std;

int main() {
	
	cout << "--Welcome to the npcLibTest module.--" << endl;

	cout << endl << "--Now instantiating the World--" << endl;
	World newWorld;

	cout << endl << "--Now parsing the NPCs--" << endl;

	cout << endl << "--Now instantiating the Users--" << endl;

	shared_ptr<User> PlayerOne( new User(false, "PlayerOne", "abc123", newWorld.getRoom(0), "This is PlayerOne."));

	newWorld.getRoom(0)->addUser(PlayerOne);

	cout << endl << "--Looking at Current Room--" << endl;
	cout << PlayerOne->getRoom()->getDesc();

	cout << endl << "--Getting a Good Look Around the Room--" << endl;
	cout << PlayerOne->lookAround();

	cout << endl << "--Looking at Exits--" << endl;
	cout << PlayerOne->lookExits();

	cout << endl << "--Getting List of Objects in the Room--" << endl;
	cout << PlayerOne->lookObjList();

	cout << endl << "--Looking at NPCs--" << endl;

	cout << endl << "--Looking at 'smurf'--" << endl;
	cout << endl << PlayerOne->lookAt("smurf") << endl;

	cout << endl << "--Here are the smurf's keywords--" << endl;
	cout << endl << PlayerOne->lookObjKeywords("smurf");

	//newWorld.NPCLib()->parseYaml();

}

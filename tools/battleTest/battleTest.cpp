#include <string>
#include <iostream>
#include <memory>
#include "world.h"
#include "user.h"


using namespace std;

int main() {
	
	cout << "--Welcome to the worldTest module.--" << endl;

	cout << endl << "--Now instantiating the World--" << endl;
	World newWorld;

	cout << endl << "--Now instantiating the Users--" << endl;

	shared_ptr<User> PlayerOne( new User(false, "PlayerOne", "abc123", newWorld.getRoom(0), "This is PlayerOne."));

	newWorld.getRoom(0)->addUser(PlayerOne);

	cout << endl << "--Player One: Looks Around--" << endl;
	cout << PlayerOne->lookAround() << endl;

	cout << endl << "--Player One: Looks At glasses--" << endl;
	cout << PlayerOne->lookAt("glasses") << endl;

	cout << endl << "--Player One: Takes glasses--" << endl;
	cout << PlayerOne->takeItem("glasses") << endl;

	cout << endl << "--Player One: Looks at Inventory--" << endl;
	cout << PlayerOne->viewInventory() << endl;

	cout << endl << "--Player One: Uses Glasses--" << endl;
	cout << PlayerOne->useItem("glasses") << endl;

	cout << endl << "--Player One: Looks Around--" << endl;
	cout << PlayerOne->lookAround() << endl;

	cout << endl << "--Player One: Looks At Handy--" << endl;
	cout << PlayerOne->lookAt("handy") << endl;

	cout << endl << "--Player One: Attacks Handy--" << endl;
	cout << PlayerOne->attackNPC("handy") << endl;

	cout << endl << "--Player One: Attacks Brainy--" << endl;
	cout << PlayerOne->attackNPC("brainy") << endl;



	//User PlayerOne(false, "Player One", "abc123", newWorld.getRoom(0), "This is Player One.");
	//User PlayerTwo(false, "Player One", "abc123", newWorld.getRoom(0), "This is Player Two.");


	cout << endl << "--EndTest!--" << endl;
}

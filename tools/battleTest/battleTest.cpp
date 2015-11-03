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

	cout << endl << "--Player One: Looks At Potion--" << endl;
	cout << PlayerOne->lookAt("Potion") << endl;

	cout << endl << "--Player One: Takes Potion--" << endl;
	cout << PlayerOne->takeItem("Potion") << endl;

	cout << endl << "--Player One: Looks at Inventory--" << endl;
	cout << PlayerOne->viewInventory() << endl;

	cout << endl << "--Player One: Uses Potion--" << endl;
	cout << PlayerOne->useItem("Potion") << endl;

	cout << endl << "--Player One: Looks Around--" << endl;
	cout << PlayerOne->lookAround() << endl;

	cout << endl << "--Player One: Looks At Knight--" << endl;
	cout << PlayerOne->lookAt("knight") << endl;

	cout << endl << "--Player One: Attacks Servant--" << endl;
	cout << PlayerOne->attackNPC("servant") << endl;

	cout << endl << "--Player One: Attacks Knight--" << endl;
	cout << PlayerOne->attackNPC("knight") << endl;



	//User PlayerOne(false, "Player One", "abc123", newWorld.getRoom(0), "This is Player One.");
	//User PlayerTwo(false, "Player One", "abc123", newWorld.getRoom(0), "This is Player Two.");


	cout << endl << "--EndTest!--" << endl;
}

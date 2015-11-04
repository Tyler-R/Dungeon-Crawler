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
	shared_ptr<User> PlayerTwo( new User(false, "PlayerTwo", "abc123", newWorld.getRoom(0), "This is PlayerTwo."));

	newWorld.getRoom(0)->addUser(PlayerOne);
	newWorld.getRoom(0)->addUser(PlayerTwo);

	//User PlayerOne(false, "Player One", "abc123", newWorld.getRoom(0), "This is Player One.");
	//User PlayerTwo(false, "Player One", "abc123", newWorld.getRoom(0), "This is Player Two.");

	cout << endl << "--Look at Room without Users--" << endl;
	cout << PlayerOne->lookObjList();

	cout << endl << "--Now testing interaction with Current Room--" << endl;	

	cout << endl << "--Looking at Current Room--" << endl;
	cout << PlayerOne->getRoom()->getDesc();

	cout << endl << "--Getting a Good Look Around the Room--" << endl;
	cout << PlayerOne->lookAround();

	cout << endl << "--Looking at Exits--" << endl;
	cout << PlayerOne->lookExits();

	cout << endl << "--Getting List of Objects--" << endl;
	cout << PlayerOne->lookObjList();


	cout << endl << "--Printing Keywords of Current Room--" << endl;

	PlayerOne->getRoom()->printKeywords();

	cout << endl << "--Adding New Keywords to Room--" << endl;
	PlayerOne->getRoom()->addKeyword("Foyer");
	PlayerOne->getRoom()->addKeyword("Entrance Hall");
	PlayerOne->getRoom()->addKeyword("Vestibule");

	PlayerOne->getRoom()->printKeywords();

	cout << endl << "--Now using Lobby's Keywords to look at the Lobby--" << endl;
	
	cout << endl << "--Looking at 'Lobby'--" << endl;
	cout << PlayerOne->lookAt("Lobby");

	cout << endl << "--Looking at 'Foyer'--" << endl;
	cout << PlayerOne->lookAt("Foyer");

	cout << endl << "--Looking at 'vestibule'--" << endl;
	cout << PlayerOne->lookAt("vestibule");

	cout << endl << "--Now using an invalid Keyword to look at the Lobby--" << endl;

	cout << endl << "--Looking at 'caboose'--" << endl;
	cout << PlayerOne->lookAt("caboose");

	cout << endl << "----" << endl;	
	cout << endl << "----" << endl;	

	cout << endl << "--Now testing moving to different rooms--" << endl;

	cout << endl << "--From the Lobby, we move 'north'--" << endl;

	cout << PlayerOne->moveTo("north");	

	cout << endl << "--Looking at Current Room--" << endl;
	cout << PlayerOne->getRoom()->getDesc();

	cout << endl << "--Getting a Good Look at the Room--" << endl;

	cout << PlayerOne->lookAround();

	cout << endl << "--Looking at Exits--" << endl;
	cout << PlayerOne->lookExits();
	cout << endl << "--Getting List of Objects in the Room--" << endl;
	cout << PlayerOne->lookObjList();


	vector<string> bathroomKeywords;

	bathroomKeywords.push_back("Washroom");
	bathroomKeywords.push_back("Restroom");
	bathroomKeywords.push_back("Powder Room");

	cout << endl << "--Adding New Keywords to Bathroom--" << endl;
	PlayerOne->getRoom()->addKeywords(bathroomKeywords);

	PlayerOne->getRoom()->printKeywords();

	cout << endl << "--Moving to 'shower'--" << endl;

	cout << PlayerOne->moveTo("shower");

	cout << endl << "--Looking at Current Room--" << endl;
	cout << PlayerOne->getRoom()->getDesc();

	cout << endl << "--Getting a Good Look at the Room--" << endl;
	cout << PlayerOne->lookAround();

	cout << endl << "--Looking at Exits--" << endl;
	cout << PlayerOne->lookExits();
	cout << endl << "--Getting List of Objects in the Room--" << endl;
	cout << PlayerOne->lookObjList();

	cout << endl << "--Moving to 'Powder Room'--" << endl;

	cout << PlayerOne->moveTo("powder room") << endl;	

	cout << endl << "--Looking at Current Room--" << endl;
	cout << PlayerOne->getRoom()->getDesc();

	cout << endl << "--Looking at Exits--" << endl;

	cout << endl << "--Looking at Exits--" << endl;
	cout << PlayerOne->lookExits();
	cout << endl << "--Getting List of Objects in the Room--" << endl;
	cout << PlayerOne->lookObjList();

	cout << endl << "--Moving to 'east' (an invalid location)--" << endl;

	cout << PlayerOne->moveTo("east");

	cout << endl << "--Moving to 'library' (an invalid location)--" << endl;

	cout << PlayerOne->moveTo("library");

	cout << endl << "--Moving to 'foyer'--" << endl;

	cout << PlayerOne->moveTo("foyer");

	cout << endl << "--Looking at Current Room--" << endl;
	cout << PlayerOne->getRoom()->getDesc();

	cout << endl << "--Getting a Good Look at the Room--" << endl;
	cout << PlayerOne->lookAround();

	cout << endl << "--Looking at Exits--" << endl;

	cout << endl << "--Looking at Exits--" << endl;
	cout << PlayerOne->lookExits();
	cout << endl << "--Getting List of Objects in the Room--" << endl;
	cout << PlayerOne->lookObjList();

	cout << endl << "----" << endl;	
	cout << endl << "----" << endl;	

	cout << endl << "--Now testing NPC interaction--" << endl;	

	cout << endl << "--Getting List of Objects--" << endl;

	cout << endl << "--Getting List of Objects in the Room--" << endl;
	cout << PlayerOne->lookObjList();

	cout << endl << "--Looking at NPCs--" << endl;

	cout << endl << "--Looking at 'smurf'--" << endl;
	cout << endl << PlayerOne->lookAt("smurf");

	cout << endl << "--Looking at 'knight'--" << endl;
	cout << endl << PlayerOne->lookAt("knight");

	cout << endl << "--Using Keywords to look at NPCs--" << endl;

	cout << endl << "--Looking at 'brainy'--" << endl;
	cout << endl << PlayerOne->lookAt("brainy");

	cout << endl << "--Looking at 'handy'--" << endl;
	cout << endl << PlayerOne->lookAt("handy");

	cout << endl << "--Now looking at lists of Keywords for each Object.--" << endl;

	cout << endl << "--Here are the handy's keywords--" << endl;
	cout << endl << PlayerOne->lookObjKeywords("handy");


	cout << endl << "--Here are the lobby's keywords--" << endl;
	cout << endl << PlayerOne->lookObjKeywords("lobby");

	cout << endl << "--Here are the north door's keywords--" << endl;
	cout << endl << PlayerOne->lookObjKeywords("north");
	

	cout << endl << "--Removing Keywords from lobby--" << endl;
	PlayerOne->getRoom()->removeKeyword("foyer");

	PlayerOne->getRoom()->removeKeyword("entrance hall");

	PlayerOne->getRoom()->removeKeyword("vestibule");

	//PlayerOne->getRoom()->removeKeyword("lobby");  //causes segfault

	cout << endl << "--Here are the lobby's keywords--" << endl;
	cout << endl << PlayerOne->lookObjKeywords("lobby");

	cout << endl << "--Now Player Two Leaves the Lobby to go to the Bathroom.--" << endl;

	cout << PlayerTwo->moveTo("north");

	cout << endl << "--Check to see that Player Two is gone.--" << endl;
	cout << endl << "--Getting List of Objects in the Room--" << endl;
	cout << PlayerOne->lookObjList();


	cout << endl << "--Now removing all NPCs from the Room--" << endl;
	for (auto & npc : PlayerOne->getRoom()->getNPCs()) {
		PlayerOne->getRoom()->removeNPC(npc->getID());
	}

 	cout << endl << "--Getting List of Objects in the Room--" << endl;
	cout << PlayerOne->lookObjList();


	cout << endl << "--Now let's have Player One take berries--" << endl;
	cout << PlayerOne->takeItem("berries");

	cout << endl << "--Getting List of Objects in the Room--" << endl;
	cout << PlayerOne->lookObjList();


	cout << endl << "--Try and take another berries (even though there are none left)--" << endl;
	cout << PlayerOne->takeItem("berries");

	cout << endl << "--Getting List of Objects in the Room--" << endl;
	cout << PlayerOne->lookObjList();

	cout << endl << "--Take glasses--" << endl;
	cout << PlayerOne->takeItem("glasses");

	cout << endl << "--Player One: Looks at Inventory--" << endl;
	cout << PlayerOne->viewInventory() << endl;

	cout << endl << "--Toss glasses--" << endl;
	cout << PlayerOne->tossItem("glasses");

	cout << endl << "--Player One: Looks at Inventory--" << endl;
	cout << PlayerOne->viewInventory() << endl;

	cout << endl << "--Player One requests description of berries from their inventory--" << endl;
	cout << PlayerOne->getInvItemLongDesc("berries") << endl;

	cout << endl << "--EndTest!--" << endl;
}

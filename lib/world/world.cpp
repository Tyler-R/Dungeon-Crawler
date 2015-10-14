/*World CLASS

This is a game class that contains attributes and methods for each room contained in the game world.

Created By: Sarah Kim Dao
*/

#include "world.h"

World::World(){
	Room* start = new Room("Start","no_desc","no_extDesc");
	Room* lobby = new Room("Lobby","This is a lobby","The lobby is cool and clean");
	Room* bathroom = new Room("Bathroom","This is a bathroom","The bathroom has heated floors.");
	Room* kitchen = new Room("Kitchen","This is a kitchen","The kitchen is sparkling.");
	Room* porch = new Room("Porch","This is a porch","The porch is a little worn.");
	Room* study = new Room("Study","This is a study","The study is tidy and full of books.");
	Room* bedroom = new Room("Bedroom","This is a bedroom","The bedroom is brightly lit.");
	Room* basement = new Room("Basement","This is a basement","The basement is dark and damp.");
	Room* shower = new Room("Shower","This is a shower","The shower is dry.");


	(*start).setNorth(lobby,"no_desc");

	(*lobby).setNorth(bathroom,"The North Door leads to the Bathroom \n hint: enter\'move north\' \n");
	(*lobby).setSouth(kitchen,"The South Door leads to the Kitchen \n hint: enter\'move south\'\n");
	(*lobby).setEast(porch,"The East Door leads to the Porch \n hint: enter\'move north\'\n");
	(*lobby).setWest(study,"The West Door leads to the Study\n");
	(*lobby).setUp(bedroom,"Upstairs leads to the Bedroom\n");
	(*lobby).setDown(basement,"Downstairs leads to the Basement\n");
	bathroom->createNPC();
	lobby->createNPC();
	bathroom->createNPC();
	kitchen->createNPC();
	porch->createNPC();
	study->createNPC();
	bedroom->createNPC();
	basement->createNPC();
	shower->createNPC();
	(*bathroom).setSouth(lobby,"The South Door leads to the Lobby");
	(*kitchen).setNorth(lobby,"The North Door leads to the Lobby");
	(*porch).setWest(lobby,"The West Door leads to the Lobby");
	(*study).setEast(lobby,"The East Door leads to the Lobby");
	(*bedroom).setDown(lobby,"Downstairs leads to the Lobby");
	(*basement).setUp(lobby,"Upstairs leads to the Lobby");

	(*bathroom).setNorth(shower,"The North Door leads to the shower");
	(*shower).setSouth(bathroom,"The South Door leads to the bathroom");

	roomList.push_back(start);
	roomList.push_back(lobby);
	roomList.push_back(bathroom);
	roomList.push_back(kitchen);
	roomList.push_back(porch);
	roomList.push_back(study);
	roomList.push_back(bedroom);
	roomList.push_back(basement);

	currentRoom = start;

	getCurrentRoom()->goNorth(getCurrentRoom());

	//NPC* monster = new NPC("monster","id:111");
	//NPC* creature = new NPC("creature","id:222");

	//cout << (*monster).getName() << endl;
	//cout << (*creature).getName() << endl;
	//cout << (*monster).getDes() << endl;
	//cout << (*creature).getDes() << endl;

	//(*lobby).getNPCs().push_back(*monster);

	//(*lobby).getNPCs().push_back(*creature);

	//string monstername=(*lobby).getNPCs().at[0].getName();

}

World::~World(){
	//for (int i = 0; i<(roomList.size()); i++){
	//	delete roomList.at(i);
	//}
}

World::World(World &obj){
	//currentRoom = obj.getCurrentRoom();

	for (int i=0; i<obj.roomList.size(); i++){
		roomList.push_back(obj.roomList[i]);
	}
}

vector<Room*> World::getRoomList(){
	return roomList;
}


Room* World::getRoom(int i){
	return roomList.at(i);
}

Room* World::getCurrentRoom(){
	return currentRoom;
}
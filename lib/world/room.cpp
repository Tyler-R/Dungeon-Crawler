/*Room CLASS

This is a game class that contains attributes and methods for each room contained in the game world.

Created By: Sarah Kim Dao
*/

#include <strings.h>
#include "room.h"



Room::Room(){
	id = "no_id";
	name = "no_name";
	desc = "no_desc";
	extDesc = "no_extDesc";
}

Room::Room(string inputId, string inputName, string inputDesc, string inputExtDesc){
	id = inputId;
	name = inputName;
	desc = inputDesc;
	extDesc = inputExtDesc;

	keywordList.push_back(inputName);
}

Room::Room(Room &room){
	id = room.getId();
	name = room.getName();
	desc = room.getDesc();
	extDesc = room.getExtDesc();

	for (auto & keyword : room.getKeywords()) {
	    keywordList.push_back(keyword);
	}

	for (auto & door : room.getDoorList()) {
	    doorList.push_back(door);
	}

}

Room::~Room(){
	for (auto & door : doorList) {
	    delete door;
	}
}

string Room::getId(){
	return id;
}

string Room::getName(){
	return name;
}

string Room::getDesc(){
	return desc;
}

string Room::getExtDesc(){
	return extDesc;
}

shared_ptr<NPC> Room::getNPC(string npcName) {
	for( auto &npc : npcList ) {
		if( npc->searchKeyword( npcName ) ) {
			return npc;
		}
	}

	return NULL;
}


vector<string> Room::getKeywords(){
	return keywordList;
}

vector<shared_ptr<NPC>> Room::getNPCs(){
	return npcList;
}

vector<shared_ptr<Item>> Room::getItems(){
	return itemList;
}

vector<shared_ptr<User>> Room::getUsers(){
	return userList;
}

shared_ptr<Entity> Room::getEntity(string entityName) {
	for(auto user : userList) {
		if(user->getUserName().compare(entityName) == 0) {
			return user;
		}
	}

	for(auto npc : npcList) {
		if(npc->searchKeyword(entityName)) {
			return npc;
		}
	}

	return nullptr;
}


void Room::setId(string s){
	id = s;
}

void Room::setName(string s){
	name = s;
}

void Room::setDesc(string s){
	desc = s;
}
void Room::setExtDesc(string s){
	extDesc = s;
}


void Room::addKeyword(string s){
	keywordList.push_back(s);
}

void Room::addKeywords(vector<string> inputKeywords){
	for (auto & keyword : inputKeywords) {
	    addKeyword(keyword);
	}
}

void Room::removeKeyword(string s){
	for (int i = 0; i<keywordList.size(); i++) {
		if (0 == strcasecmp(s.c_str(), keywordList.at(i).c_str())){
			keywordList.erase (keywordList.begin()+i);
		}
	}
}

bool Room::findKeyword(string s){
	for (auto & keyword : keywordList) {
		if(0 == strcasecmp(s.c_str(), keyword.c_str())){
			return true;
	   	}
	}
		return false;
}

void Room::printKeywords(){ //To be used by the Room's Test Module only!
	for (auto & keyword : keywordList) {
	    cout << keyword << endl;
	}
}


vector<string> Room::getObjKeywords(string objName){ //Gets a List of an Object's Keywords.
	if ( findKeyword(objName) ){
		return getKeywords();
	}
	for (auto & door : doorList) {
		if ( door->findKeyword(objName) || door->getLeadsTo()->findKeyword(objName)){
			return door->getKeywords();
		}
	}
	for (auto & npc : npcList) {
		if ( npc->searchKeyword(objName)){
			return npc->getKeyword();
		}
	}

	for (auto & item : itemList) {
		if ( item->searchKeyword(objName)){
			return item->getKeyword();
		}
	}
	vector<string> result;
	result.push_back("Object not found!");
	return result;
}

void Room::addDoor(string inputId,string inputDir, string inputDesc, shared_ptr<Room>inputRoom){
 	doorList.push_back(new Door(inputId,inputDir,inputDesc, inputRoom));
}

vector<Door*> Room::getDoorList(){
	return doorList;
}

//LookAround
string Room::getDoorDescList(){
	//This method returns a description of all of the room's doors.
	string result = "";
	for (auto & door : doorList){
		result = result + "Looking " + door->getDir() + ": " + door->getDesc() + "\n";
	}
	return result;
}

string Room::getObjList(){
	//This method returns a list of strings containing the names of every door, npc, item, and user in the room.
	string result = "";
	result + "\n";
	for (auto & door : doorList) {
	    result = result + (door->getLeadsTo()->getName()) + "\n";
	}

	for (auto & npc : npcList) {
	    result = result + (npc->getShortDesc()) + "\n";
	}

	for (auto & user : userList) {
	    result = result + (user->getUserName()) + "\n";
	}

	for (auto &item : itemList){
	    result = result + (item->getShortDesc()) + "\n";
	}
	result + "\n";
	return result;
}

string Room::lookAround(){
		//This method is used if the user types the "look <noun>" command and <noun> is their current room.

		string objRoom = "";

		objRoom += "\n";

		objRoom += getDesc() + "\n"; 

		for(auto &keyword: keywordList){

			objRoom += "You see a " + keyword + " in the Room.\n";
		}

		if (!userList.empty()){
			for(auto &user: userList){
				objRoom += "You see " + user->getUserName() + " in the Room.\n";
			}
		}

		if (!npcList.empty()){
			for(auto &npc: npcList){
				objRoom += "You see " + npc->getShortDesc() + " in the Room.\n";
			}
		}

		if (!itemList.empty()){
			for(auto &item: itemList){

				objRoom += "You see " + item->getShortDesc() + " in the Room.\n";
			}
		}
		objRoom += "\n";
		return objRoom;

	}

string Room::lookAt(string objName){
	//This method is used if the user types the "look <noun>" command.  <noun> can be a valid keyword.

	if ( findKeyword(objName) ){
		return "\n" + getExtDesc() + "\n";
	}


	for (auto & door : doorList) {
		if ( door->getLeadsTo()->findKeyword(objName) || door->findKeyword(objName)){
			return "\n" + door->getDesc() + "\n";
		}
	}

	for (auto & npc : npcList) {
		if ( npc->searchKeyword(objName)){
			return "\n" + npc->getDescription() + "\n";
		}
	}

	for (auto & user : userList) {
		if (0 == strcasecmp(objName.c_str(), user->getUserName().c_str())){
			return "\n" + user->getDescription() + "\n";
		}
	}

	
	for (auto &item : itemList){
		if(item->searchKeyword(objName)){
			return "\n" + item->getShortDesc() + "\n";
		}
	}
	

	return "\""+objName+"\""+" not found!\n";

}

void Room::setDoorState(int doorNumber, string newState) {
	//assert(doorNumber < doorList.size());
	for (auto &door : doorList){
		if(doorNumber == stoi(getId())){
			door->setState(newState);
		}
	}
}

void Room::addUser(shared_ptr<User> user){
	userList.push_back(user);
}

void Room::removeUser(string name){
	for (int i = 0; i<userList.size(); i++) {
		if (0 == strcasecmp(name.c_str(), userList.at(i)->getUserName().c_str())){
			userList.erase(userList.begin()+i);
		}
	}
}

void Room::transferOutUser(string name, shared_ptr<Room> outRoom){
	for (int i = 0; i<userList.size(); i++) {
		if (0 == strcasecmp(name.c_str(), userList.at(i)->getUserName().c_str())){
			outRoom->addUser(userList.at(i));
			userList.erase(userList.begin()+i);
		}
	}
}

void Room::addNPC(shared_ptr<NPC> npc) {
	npcList.push_back(npc);
}

void Room::removeNPC(string npcID){
	for (int i = 0; i<npcList.size(); i++)  {
		if(npcList.at(i)->getID().compare(npcID) == 0) {
			npcList.erase(npcList.begin()+i);
		}
	}
}

void Room::addItem(shared_ptr<Item> item){
	itemList.push_back(item);
}

void Room::removeItem(string itemID){
	for (int i = 0; i<itemList.size(); i++)  {
		if(itemList.at(i)->getID().compare(itemID) == 0) {
			itemList.erase(itemList.begin()+i);
		}
	}
}

bool Room::doesItemExist(string itemID) {
	for(auto &item : itemList) {
		if(itemID.compare(item->getID()) == 0) {
			return true;
		}
	}

	return false;
}

int Room::getNumberOfNPCsWithID(string npcID) {
	int npcCount = 0;

	// for(auto &npc : npcList) {
	// 	if(npc->getID().compare(npcID) == 0) {
	// 		npcCount++;
	// 	}
	// }

	return npcCount;
}	

void Room::broadcastMessage(User *playerSendingBroadcast, string message){
	cout << "broadcasting message" << endl;

	for(auto &user : userList) {
		if(user.get() != playerSendingBroadcast) {
			user->notifySession(message);
		}
	}
}
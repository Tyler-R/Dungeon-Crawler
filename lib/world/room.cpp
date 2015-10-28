/*Room CLASS

This is a game class that contains attributes and methods for each room contained in the game world.

Created By: Sarah Kim Dao
*/

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
}

Room::Room(Room &obj){
	id = obj.getId();
	name = obj.getName();
	desc = obj.getDesc();
	extDesc = obj.getExtDesc();

}

Room::~Room(){

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

void Room::removeKeyword(string s){
	//Removes Keyword from KeywordList
}
string Room::findKeyword(string s){
	if(find(keywordList.begin(), keywordList.end(), s) != keywordList.end()){
		return "Keyword found!";
	}
		return "Keyword not found!";
	
}
void Room::printKeywords(){ //To be used by the Room's Test Module only!
	for (auto & keyword : keywordList) {
	    cout << keyword << endl;
	}
}


//LookAround

vector<string> Room::getDoorList(){
	/*
	vector<string> doorList;

	doorList.push_back(lookNorth());
	doorList.push_back(lookSouth());
	doorList.push_back(lookEast());
	doorList.push_back(lookWest());
	doorList.push_back(lookUp());
	doorList.push_back(lookDown());

	return doorList;
	*/
}


vector<string> Room::getObjList(){

	vector<string> objList;

	return objList;
}

string Room::lookAround(){

		/*
		string objRoom = "";
		for(auto &str: npcList){
			objRoom += str->getName() + " ";
		}
		objRoom = "there are " + objRoom + "in the room"+ '\n';

		return getExtDesc()+ '\n' + objRoom;
		*/
	}

string Room::getObjDesc(string objName){
	/*
	for (int i=0; i<doorList.size(); i++){

		//cout << "Matching " << objList[i]->getName() << " with " << objName << endl;
		if ( doorList[i]->getName() == objName ){
			//cout << "Match Found!" << endl;
			return doorList[i]->getDesc();
		}
	}
	for (auto &npc : npcList){
		if(objName.compare(npc->getName())==0){
			return npc->getDes();
		}
	}

	return "\""+objName+"\""+" not found!\n";
	*/
}


void Room::addDoor(string inputDir, string inputDesc, Room &inputRoom){
	shared_ptr<Door> newDoor;
	//newDoor.setDir = inputDir;
	//newDoor.setLeadsTo() = inputRoom;
}

Door* Room::findDoor(string inputDir){
	for (auto & door : doorList) {
	    if (inputDir.compare(door->getDir())==0){
		return door;
	    }
	}
	return NULL;
}








/*
void Room::createNPC(){
		
		NPC* monster = new NPC("monster","id:111");
		NPC* creature = new NPC("creature","id:222");

		npcList.push_back(monster);
		npcList.push_back(creature);
}
*/
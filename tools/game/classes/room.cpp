/*Room CLASS

This is a game class that contains attributes and methods for each room contained in the game world.

Created By: Sarah Kim Dao
*/


#include "room.h"


Room::Room(){ 

}


Room::Room(char id){ 
	//will construct new Room based on pre-existing information contained in game text files
}


Room::~Room(){
		delete North;
		delete South;
		delete East;
		delete West;
		delete Up;
		delete Down;
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
/*	

vector<keyword> Room::getKeywords(){

}
	
vector<player> Room::getPlayers(){

}

vector<monster> Room::getMonsters(){

}
*/


void Room::getId(string s){
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


/*		
void Room::setPlayers(vector<Player> p){
	playerPop = p;
}

void Room::setMonsters(vector<monster> m){
	monsterPop = m;
}

void Room::setKeywords(vector<monster> m){
	monsterPop = m;
}
*/


void Room::setNorth(Room *input_id, string input_desc){
	North->leadsTo = input_id;
	North->desc = input_desc;
}

void Room::setSouth(Room *input_id, string input_desc){
	South->leadsTo = input_id;
	South->desc = input_desc;
}

void Room::setEast(Room *input_id, string input_desc){
	East->leadsTo = input_id;
	East->desc = input_desc;
}	

void Room::setWest(Room *input_id, string input_desc){
	West->leadsTo = input_id;
	West->desc = input_desc;
}

void Room::setUp(Room *input_id, string input_desc){
	Up->leadsTo = input_id;
	Up->desc = input_desc;
}

void Room::setDown(Room *input_id, string input_desc){
	Down->leadsTo = input_id;
	Down->desc = input_desc;
}


Room::Door Room::getNorth(){
	return *North;
}


Room::Door Room::getSouth(){
	return *South;
}

Room::Door Room::getEast(){
	return *East;
}

Room::Door Room::getWest(){
	return *West;
}

Room::Door Room::getUp(){
	return *Up;
}

Room::Door Room::getDown(){
	return *Down;
}




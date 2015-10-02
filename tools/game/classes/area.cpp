//Created By: Sarah Kim Dao
// Constructors

#include "area.h" //declarations for queue functions
#include <iostream>

Area::Area(){ 
	
}

Area::Area(string name,string desc){ 
	
	Name = name;
	Desc = desc;
	
}

Area::Area(char id){ 

}

// Destructor
Area::~Area(){
		
}

string Area::getName(){
	return Name;
}

string Area::getDesc(){
	return Desc;
}

/*		
vector<player> Area::getPlayers(){

}

vector<monster> Area::getMonsters(){

}
*/

	
Area Area::getNorth(){
	return *North;
}

Area Area::getSouth(){
	return *South;
}

Area Area::getEast(){
	return *East;
}

Area Area::getWest(){
	return *West;
}


void Area::setName(string n){
	Name = n;
}
void Area::setDesc(string d){
	Desc = d;
}

/*		
void Area::setPlayers(vector<Player> p){
	playerPop = p;
}

void Area::setMonsters(vector<monster> m){
	monsterPop = m;
}
*/

void Area::setNorth(Area *n){
	North = n;
}

void Area::setSouth(Area *s){
	South = s;
}

void Area::setEast(Area *e){
	East = e;
}

void Area::setWest(Area *w){
	West = w;
}


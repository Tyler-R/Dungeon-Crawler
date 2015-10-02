/*Location CLASS

This is a game class that contains attributes and methods for each location contained in the game world.

Created By: Sarah Kim Dao
*/


#include "location.h"
#include <iostream>

/*Constructors*/
Location::Location(){ 
	
}

Location::Location(string name,string desc){ 
	
	Name = name;
	Desc = desc;
	
}

Location::Location(char id){ 
	//will construct new Location based on pre-existing information contained in game text files
}

/*Destructor*/
Location::~Location(){
		
}

/*Getters and Setters*/
string Location::getName(){
	return Name;
}

string Location::getDesc(){
	return Desc;
}

/*		
vector<player> Location::getPlayers(){

}

vector<monster> Location::getMonsters(){

}
*/


Location Location::getNorth(){
	return *North;
}

Location Location::getSouth(){
	return *South;
}

Location Location::getEast(){
	return *East;
}

Location Location::getWest(){
	return *West;
}


void Location::setName(string n){
	Name = n;
}
void Location::setDesc(string d){
	Desc = d;
}

/*		
void Location::setPlayers(vector<Player> p){
	playerPop = p;
}

void Location::setMonsters(vector<monster> m){
	monsterPop = m;
}
*/

void Location::setNorth(Location *n){
	North = n;
}

void Location::setSouth(Location *s){
	South = s;
}

void Location::setEast(Location *e){
	East = e;
}

void Location::setWest(Location *w){
	West = w;
}


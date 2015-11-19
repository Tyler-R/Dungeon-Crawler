/*Door CLASS

This is a game class that contains attributes and methods for doors that allow the player to move from one room to the next.

Created By: Sarah Kim Dao
*/

#include <strings.h>
#include "room.h"

Door::Door(){
	id = "no_id";
	//leadsTo = NULL;
	dir = "no_dir";
	desc = "no_desc";  	
}

Door::Door(string inputId, string inputDir, string inputDesc, shared_ptr<Room> &inputLeadsTo){
	id = inputId;
	leadsTo = inputLeadsTo;	//LEAK
	dir = inputDir;
	desc = inputDesc;  

	keywordList.push_back(dir);
}

Door::Door(Door &obj){
	id = obj.getId();
	leadsTo = obj.getLeadsTo(); //LEAK
	dir = obj.getDir();
	desc = obj.getDesc();  

	for (auto & keyword : obj.keywordList) {
	    keywordList.push_back(keyword);
	}
}

Door::~Door(){

}

void Door::setId(string s){
	id = s;
}

void Door::setDir(string s){
	dir = s;
}

void Door::setDesc(string s){
	desc = s;
}

void Door::setLeadsTo(shared_ptr<Room> r){
	leadsTo = r;
}


string Door::getId(){
	return id;
}

string Door::getDir(){
	return dir;
}

string Door::getDesc(){
	return desc;
}

vector<string> Door::getKeywords(){
	return keywordList;
}

shared_ptr<Room> Door::getLeadsTo(){
	return leadsTo.lock();
}
		
void Door::addKeyword(string s){
	keywordList.push_back(s);
}

void Door::removeKeyword(string s){
	//Removes Keyword from KeywordList
}
	
		
bool Door::findKeyword(string s){
	for (auto & keyword : keywordList) {
		if(0 == strcasecmp(s.c_str(), keyword.c_str())){
			return true;
	   	}
	}
	return false;
}

void Door::setState(string newState) {
	state = newState;
}


void Door::printKeywords(){
	for (auto & keyword : keywordList) {
	    cout << keyword << endl;
	}
}


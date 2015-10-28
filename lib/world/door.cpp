/*Door CLASS

This is a game class that contains attributes and methods for doors that allow the player to move from one room to the next.

Created By: Sarah Kim Dao
*/


#include "room.h"

Door::Door(){
	id = "no_id";
	leadsTo = NULL;
	dir = "no_dir";
	desc = "no_desc";  	
}

Door::Door(string inputId, string inputDir, string inputDesc, Room &inputLeadsTo){
	id = inputId;
	leadsTo = &inputLeadsTo;
	dir = inputDir;
	desc = inputDesc;  
}

Door::Door(Door &obj){
	id = obj.getId();
	leadsTo = obj.getLeadsTo();
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

void Door::setLeadsTo(Room &r){
	leadsTo = &r;
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

Room* Door::getLeadsTo(){
	return leadsTo;
}
		
void Door::addKeyword(string s){
	keywordList.push_back(s);
}

void Door::removeKeyword(string s){
	//Removes Keyword from KeywordList
}
	
		
string Door::findKeyword(string s){

	if(find(keywordList.begin(), keywordList.end(), s) != keywordList.end()){
		return "Keyword found!";
	}
		return "Keyword not found!";
	
}


void Door::printKeywords(){
	for (auto & keyword : keywordList) {
	    cout << keyword << endl;
	}
}


/*Door CLASS

This is a game class that contains attributes and methods for doors that allow the player to move from one room to the next.

Created By: Sarah Kim Dao
*/


#include "room.h"

Door::Door(){
	leadsTo = NULL;
	dir = "no_dir";
	desc = "no_desc";  	
}

Door::Door(string inputDir, string inputDesc){
	leadsTo = NULL;
	dir = inputDir;
	desc = inputDesc;  
}

Door::Door(Door &obj){
	leadsTo = obj.getLeadsTo();
	dir = obj.getDir();
	desc = obj.getDesc();  

	for (auto & keyword : obj.keywordList) {
	    keywordList.push_back(keyword);
	}
}

Door::~Door(){

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


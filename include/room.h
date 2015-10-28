/*Header file for Room.cpp
Created By: Sarah Kim Dao
*/

#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <memory>

using namespace std;

class Door;

class Room {
	private:
		string id;
		string name;
		string desc;  	  	   	
		string extDesc;

		vector<string> keywordList;

		vector<Door*> doorList;
		//vector<NPC> npcList;
		//vector<User> userList;
		
	
			
	public: 

		Room();
		Room(Room &room);

		Room(string inputId, string inputName, string inputDesc, string inputExtDesc); 

		~Room();
 
		string getId();
		string getName();
		string getDesc();  
		string getExtDesc();

		vector<string> getKeywords();

		//vector<NPC*> getNPCs();
		//vector<User> getUsers();	

		
		void setId(string s);
		void setName(string s);
		void setDesc(string s);
		void setExtDesc(string s);

		void addKeyword(string s);
		void removeKeyword(string s);
		bool findKeyword(string s);

		void printKeywords(); //To be used by the Room's Test Module only!	

		vector<string> getDoorDescList();	
		vector<string> getObjList();
	
		string lookAround();
		string lookAt(string objName);

		string moveTo(string dir, shared_ptr<Room> &currentRoom);

		void createNPC();
		void addDoor(string inputId, string inputDir, string inputDesc, shared_ptr<Room> inputRoom);

		Door* getDoor(string inputDir);
};




class Door {
	private:
		string id;
		string dir;
		string desc;  	  	   	
		shared_ptr<Room> leadsTo;

		vector<string> keywordList;
			
	public: 
	
		Door();

		Door(string inputId, string inputDir, string inputDesc, shared_ptr<Room> &inputLeadsTo);

		Door(Door &obj);

		~Door();

		void setId(string s);
		void setDir(string s);
		void setDesc(string s);
		void setLeadsTo(shared_ptr<Room> r);


		string getId();
		string getDir();
		string getDesc();

		vector<string> getKeywords();

		shared_ptr<Room> getLeadsTo();
		void addKeyword(string s);
		void removeKeyword(string s);
		bool findKeyword(string s);
		void printKeywords(); //To be used by the Door's Test Module only!

};

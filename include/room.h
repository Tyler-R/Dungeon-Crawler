/*Header file for Room.cpp
Created By: Sarah Kim Dao
*/

#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <memory>
#include <assert.h>

#include "npc.h"
#include "item.h"
#include "user.h"


using namespace std;

class Door;

class User; //Forward Declaration since Room class and User class refer to eachother

class Room {
	private:
		string id;
		string name;
		string desc;  	  	   	
		string extDesc;

		vector<string> keywordList;

		vector<Door*> doorList;
		vector<shared_ptr<NPC>> npcList;
		vector<shared_ptr<Item>> itemList;
		vector<shared_ptr<User>> userList;
		
	
			
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
		vector<shared_ptr<NPC>> getNPCs();
		vector<shared_ptr<Item>> getItems();
		vector<shared_ptr<User>> getUsers();	

		int getNumberOfNPCsWithID(string npcID);

		
		void setId(string s);
		void setName(string s);
		void setDesc(string s);
		void setExtDesc(string s);

		void addKeyword(string s);
		void addKeywords(vector<string> inputKeywords);
		void removeKeyword(string s);
		bool findKeyword(string s);
		void printKeywords(); //To be used by the Room's Test Module only!	
		vector<string> getObjKeywords(string objName);

		void addDoor(string inputId, string inputDir, string inputDesc, shared_ptr<Room> inputRoom);
		vector<Door*> getDoorList();
		string getDoorDescList();	
		string getObjList();
	
		string lookAround();
		string lookAt(string objName);

		void setDoorState(int doorNumber, string newState);

		void addUser(shared_ptr<User> user);
		void removeUser(string name);
		void transferOutUser(string name, shared_ptr<Room> outRoom);

		void createNPC();
		void addNPC(shared_ptr<NPC> npc);
		void removeNPC(string npcID);

		void createItem();
		void addItem(shared_ptr<Item> item);
		void removeItem(string itemID);

		bool doesItemExist(string itemID);
		

		void broadcastMessage(User *playerSendingBroadcast, string message);

};




class Door {
	private:
		string id;
		string dir;
		string desc;  	  	   	
		weak_ptr<Room> leadsTo;

		vector<string> keywordList;
		string state = "unlocked";
			
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
		shared_ptr<Room> getLeadsTo();

		vector<string> getKeywords();
		void addKeyword(string s);
		void removeKeyword(string s);
		bool findKeyword(string s);
		void printKeywords(); //To be used by the Door's Test Module only!

		void setState(string newState);
		
};

/*Header file for Room.cpp
Created By: Sarah Kim Dao
*/


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
		Room(Room &obj);

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
		string findKeyword(string s);
		void printKeywords(); //To be used by the Room's Test Module only!

		void moveTo(string dir);

		vector<string> getDoorList();	
		vector<string> getObjList();
	
		string lookAround();
		string getObjDesc(string objName);

		//void addNPC();
		void addDoor(string inputDir, string inputDesc, Room &inputRoom);
		Door* findDoor(string inputDir);
};




class Door {
	private:
		string dir;
		string desc;  	  	   	
		Room* leadsTo;

		vector<string> keywordList;
			
	public: 
	
		Door();

		Door(string inputDir, string inputDesc);

		Door(Door &obj);

		~Door();

		void setDir(string s);
		void setDesc(string s);
		void setLeadsTo(Room &r);

		string getDir();
		string getDesc();

		vector<string> getKeywords();

		Room* getLeadsTo();
		void addKeyword(string s);
		void removeKeyword(string s);
		string findKeyword(string s);

		void printKeywords(); //To be used by the Door's Test Module only!

};
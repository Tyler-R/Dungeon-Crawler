/*Header file for Room.cpp
Created By: Sarah Kim Dao
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Room {
	private:
		//string id;
		string name;
		string desc;  	  	   	
		string extDesc;

		//vector<Keyword> keywords;
		//vector<Player> playerPop;	
		//vector<NPC> npcPop;

		struct Door {
			//keywords<string> Keywords;
			Room *leadsTo;
			string desc;
		};

		Door *north;			
		Door *south;
		Door *east;
		Door *west;	
		Door *up;			
		Door *down;

	public: 

		Room();

		Room(Room &obj);

		Room(string input_name, string input_desc, string input_extDesc); 

		/* Construct New Room from Info Contained in Text Files */
		Room(char id); 

		~Room();
 
		//string getId();
		string getName();
		string getDesc();
		string getExtDesc();

		//vector<Keyword> getKeywords();
		//vector<User> getUsers();	
		//vector<NPC> NPCs();	
		
		//void getId(string s);
		void setName(string s);
		void setDesc(string s);
		void setExtDesc(string s);

		//void setKeywords(vector<Keyword> keywords);
		//void setUser(vector<Player> p);	
		//void setNPC(vector<NPC> m);	

		void setNorth(Room *input_id, string input_desc);
		void setSouth(Room *input_id, string input_desc);
		void setEast(Room *input_id, string input_desc);
		void setWest(Room *input_id, string input_desc);
		void setUp(Room *input_id, string input_desc);
		void setDown(Room *input_id, string input_desc);

		Door getNorth();
		Door getSouth();
		Door getEast();
		Door getWest();
		Door getUp();
		Door getDown();
		
		string lookNorth();
		string lookSouth();
		string lookEast();
		string lookWest();
		string lookUp();
		string lookDown();

		Room * getNorthLeadsTo();
		Room * getSouthLeadsTo();
		Room * getEastLeadsTo();
		Room * getWestLeadsTo();
		Room * getUpLeadsTo();
		Room * getDownLeadsTo();

		/*

		WARNING: The below methods currently leak.

		*/

		void goNorth(Room *current);
		void goSouth(Room *current);
		void goEast(Room *current);
		void goWest(Room *current);
		void goUp(Room *current);
		void goDown(Room *current);	
};
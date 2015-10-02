/*Header file for location.cpp
Created By: Sarah Kim Dao
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Location {
	public:
		Location(); 
		Location(string name,string desc);

		/* Construct New Locations from Info Contained in Text Files */
		Location(char id); 

		~Location(); 

		string getName();
		string getDesc();
		
		/* Get Player and Monster Populations */
		//vector<Player> getPlayers();	
		//vector<Monster> getMonsters();	
	
		/* Get Adjacent Locations */
		Location getNorth();
		Location getSouth();
		Location getEast();
		Location getWest();

		void setName(string n);
		void setDesc(string d);
		
		/* Set Player and Monster Populations */
		//void setPlayers(vector<Player> p);	
		//void setMonsters(vector<Monster> m);	

		/* Set Adjacent Location */
		void setNorth(Location *n);
		void setSouth(Location *s);
		void setEast(Location *e);
		void setWest(Location *w);
		
	private:
		string Name;
		string Desc;  	  	   	

		/* Pointers to Adjacent Locations */
		Location *North;			
		Location *South;
		Location *East;
		Location *West;	

		//vector<Player> playerPop;	
		//vector<Monster> monsterPop;
		
};

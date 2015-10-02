/*Header file for area.cpp
Created By: Sarah Kim Dao
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Area {
	public:
		Area(); 
		Area(string name,string desc);

		/* Construct New Area from Info Contained in Text Files */
		Area(char id); 

		~Area(); 

		string getName();
		string getDesc();
		
		/* Get Player and Monster Populations */
		//vector<Player> getPlayers();	
		//vector<Monster> getMonsters();	
	
		/* Get Adjacent Areas */
		Area getNorth();
		Area getSouth();
		Area getEast();
		Area getWest();

		void setName(string n);
		void setDesc(string d);
		
		/* Set Player and Monster Populations */
		//void setPlayers(vector<Player> p);	
		//void setMonsters(vector<Monster> m);	

		/* Set Adjacent Areas */
		void setNorth(Area *n);
		void setSouth(Area *s);
		void setEast(Area *e);
		void setWest(Area *w);
		
	private:
		string Name;
		string Desc;  	  	   	

		/* Pointers to Adjacent Areas */
		Area *North;			
		Area *South;
		Area *East;
		Area *West;	

		//vector<Player> playerPop;	
		//vector<Monster> monsterPop;
		
};

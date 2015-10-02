#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Area {
	public:
		/* Constructors */
		Area(); 
		Area(string name,string desc);
		Area(char id); 		

		/* Destructor */
		~Area(); 

		/* Getters and Setters */
		string getName();
		string getDesc();
		
		//vector<Player> getPlayers();	
		//vector<Monster> getMonsters();	
	
		Area getNorth();
		Area getSouth();
		Area getEast();
		Area getWest();

		void setName(string n);
		void setDesc(string d);
		
		//void setPlayers(vector<Player> p);	
		//void setMonsters(vector<Monster> m);	

		void setNorth(Area *n);
		void setSouth(Area *s);
		void setEast(Area *e);
		void setWest(Area *w);
		
	private:
		string Name;
		string Desc;  	  	   	

		Area *North;			
		Area *South;
		Area *East;
		Area *West;	

		//vector<Player> playerPop;	
		//vector<Monster> monsterPop;
		
};

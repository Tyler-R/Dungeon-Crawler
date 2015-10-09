#ifndef NPCS_H_
#define NPCS_H_

#include "monster.h"
#include "creature.h"

using namespace std;

class NPCS {

public:
	NPCS(string type, string ID); // type(monster or creature), the ID of this NPC



	void setID();	

	string getID() const;
	string getType() const;

	string getName() const;

	int getHP() const;

	int getDamage()const;

	bool getAlive()const;	// live or dead




private:
	string npcName();
	string npcType();
	int npcHP();
	bool isAlive();
	int npcDamage();


	void setName();
	void setType();
	void setHP();
	void setAlive();
	void setDamage();

}
//
//  npc.h
//  TeamProject_cmpt373
//
//  Created by JasonYang on 2015-10-08.
//  Copyright © 2015 JasonYang. All rights reserved.
//

#ifndef NPC_H_
#define NPC_H_

#include "monster.h"
#include "creature.h"

using namespace std;

class NPC {
    
private:
    // attributes
    string npcID;
    string npcName;
    string npcType;
    int npcHP;
    bool isAlive;
    int npcDamage;
    
    // functions
    void setName(string s);
    void setType(string s);
    void setHP(int i);
    void setAlive(bool b);
    void setDamage(int i);

public:
    //constructor
	NPC(string type, string ID); // type(monster or creature), the ID of this NPC

    // functions
	void setID(string id);
	string getID() const;
	string getType() const;
	string getName() const;
	int getHP() const;
	int getDamage()const;
	bool getAlive()const;	// live or dead

	// helper function
	void checkNPC() const;	// print out all attributes of npc

};
#endif
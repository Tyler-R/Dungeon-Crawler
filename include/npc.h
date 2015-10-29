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

#include <vector>

using namespace std;

class NPC {
    
private:
    // attributes
    string npcID;
    string npcDescription;
    string longDesc;
    string shortDesc;
    vector<string> keyword;

    // save for later
    string npcName;
    string npcType;
    int npcHP;
    bool isAlive;
    int npcDamage;
    string npcDes;

    
    // functions
    void setName(string s);
    void setType(string s);
    void setHP(int i);
    void setAlive(bool b);
    void setDamage(int i);
    void setDes(string des);

public:
    //constructor
	NPC(string type, string ID); // type(monster or creature), the ID of this NPC
    NPC(string id);
    //destructor
    // ~NPC();
    
    // functions
	void setID(string id);
	string getID() const;

    // save for later
	string getType() const;
	string getName() const;
	int getHP() const;
	int getDamage()const;
	bool getAlive()const;	// live or dead
    string getDes()const;



    // descriptions
    void addDescription(string s);
    void addKeyword(vector<string>& s);
    void addLongDesc(string s);
    void addShortDesc(string s);

    string getDescription()const;
    vector<string> getKeyword()const;
    string getLongDesc()const;
    string getShortDesc()const;

    void printVector() const;

	// helper function
	void checkNPC() const;	// print out all attributes of npc

    // action
    void getHit(); // reduce HP by 1
};
#endif
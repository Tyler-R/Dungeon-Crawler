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
    // attributes (yaml)
    string npcID;
    string npcDescription;
    string longDesc;
    string shortDesc;
    vector<string> keywords;

    // save for later (status)
    string npcName;
    string npcType;
    int npcHP;
    bool isAlive;
    int npcDamage;
    string npcDes;

    
    // functions (status)
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

    // save for later (status)
	string getType() const;
	string getName() const;
	int getHP() const;
	int getDamage()const;
	bool getAlive()const;	// live or dead
    string getDes()const;



    // descriptions
    void addDescription(string s);
    void addLongDesc(string s);
    void addShortDesc(string s);
    string getDescription()const;
    string getLongDesc()const;
    string getShortDesc()const;
    
    // keyword
    void addKeyword(string s);
    void addKeywords(vector<string> s);
    bool searchKeyword(string s) const;
    void removeKeyword(string s);
    void removeAllKeyword();
    vector<string> getKeyword()const;
    // helper function ( check keywords )
    void printVector() const;


	// helper function (status)
	void checkNPC() const;	// print out all attributes of npc

    // action
    void getHit(); // reduce HP by 1
};
#endif
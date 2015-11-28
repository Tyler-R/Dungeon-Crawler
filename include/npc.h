//
//  npc.h
//  TeamProject_cmpt373
//
//  Created by JasonYang on 2015-10-08.
//  Copyright © 2015 JasonYang. All rights reserved.
//

#ifndef NPC_H_
#define NPC_H_
#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
#include "entity.h"

using namespace std;

class NPC : public Entity {
    
private:
    // attributes (yaml)
    string npcID;
    string npcDescription;
    string longDesc;
    string shortDesc;
    vector<string> keywords;

    // save for later (status)
    int npcDamage;
    string npcDes;

    const int DEFAULT_HEALTH = 10;

public:

    const int DEAD_DAMAGE = 0;


    // functions (status)
    void setAlive();
    void setDamage();

    int getDamage()const;
    
    //constructor
	NPC(string type, string ID); // type(monster or creature), the ID of this NPC
    NPC(string id);
    NPC(NPC *npc); // copy
    //destructor
    ~NPC();
    
    // functions
	void setID(string id);
	string getID() const;

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
};
#endif

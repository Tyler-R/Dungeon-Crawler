//
//  npc.cpp
//  TeamProject_cmpt373
//
//  Created by JasonYang on 2015-10-08.
//  Copyright © 2015 JasonYang. All rights reserved.
//

#include <stdio.h>
#include "npc.h"


NPC::NPC(string type, string id){
	if (type == "monster") {
		Monster tempMonster;
        
        setID(id);
		setName(tempMonster.getName());
        setType(type);
        setHP(tempMonster.getHP());
        setAlive(tempMonster.getAlive());
        setDamage(tempMonster.getDamage());
	
    }else if(type == "creature") {
        Creature tempCreature;
        
        setID(id);
        setName(tempCreature.getType());
        setType(type);
        setHP(tempCreature.getHP);
        setAlive(tempCreature.getAlive());
        setDamage(int(0));
	
    }else {
		return -1;
	}
}


void NPC::setID(string id) {
    npcID = id;
}
void NPC::setName(string s) {
    npcName = s;
}

void NPC::setType(string s) {
    npcType = s;
}

void NPC::setHP(int i) {
    npcHP = i;
}

void NPC::setAlive(bool b) {
    isAlive = b;
}

void NPC::setDamage(int i) {
    npcDamage = i;
}


string NPC::getID() const{
    return npcID;
}

string NPC::getName() const{
    return npcName;
}

string NPC::getType() const{
    return npcType;
}

int NPC::getHP() const{
    return npcHP;
}

bool NPC::getAlive() const{
    return isAlive;
}

int NPC::getDamage() const{
    return npcDamage;
}
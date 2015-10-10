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
        setType(tempMonster.getType());
        
        
	}else if(type == "creature") {

	}else {
		return -1;
	}
}


void NPC::setID(string id) {

}
void NPC::setName(string s) {

}

void NPC::setType(string s) {

}

void NPC::setHP(int i) {

}

void NPC::setAlive(bool b) {

}

void NPC::setDamage(int i) {

}


string NPC::getID() const{

}

string NPC::getName() const{

}

string NPC::getType() const{

}

int NPC::getHP() const{

}

bool NPC::getAlive() const{

}

int NPC::getDamage() const{
	
}
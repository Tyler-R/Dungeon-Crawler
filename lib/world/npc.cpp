//
//  npc.cpp
//  TeamProject_cmpt373
//
//  Created by JasonYang on 2015-10-08.
//  Copyright © 2015 JasonYang. All rights reserved.
//

#include <stdio.h>
#include "npc.h"
#include <strings.h>

// constructor (id)
NPC::NPC(string id){
    setID(id);
    setHP();
    setAlive(true);
    setDamage();
}

// for copy
NPC::NPC(NPC *npc){
    npcID = npc->getID();
    npcDescription = npc->getDescription();
    longDesc = npc->getLongDesc();
    shortDesc = npc->getShortDesc();

    for(auto & key : npc->getKeyword()){
        keywords.push_back(key);
    }
}

// Destructor
NPC::~NPC(){}

// destructor
//NPC::~NPC() {
//    delete npcID;
//    delete npcName;
//    delete npcType;
//    delete npcHP;
//    delete npcDamage;
//    delete isAlive;
//}

// Description functions
void NPC::addDescription(string s){
    npcDescription = s;
}
void NPC::addLongDesc(string s){
    longDesc = s;
}
void NPC::addShortDesc(string s){
    shortDesc = s;
}

string NPC::getDescription()const{
    return npcDescription;
}
string NPC::getLongDesc()const{
    return longDesc;
}
string NPC::getShortDesc()const{
    return shortDesc;
}

// Keyword functions
void NPC::addKeyword(string s){
    keywords.push_back(s);
}
void NPC::addKeywords(vector<string> s){
    for(auto & tempKey : s){
        addKeyword(tempKey); 
    }
}
bool NPC::searchKeyword(string s)const{
    for(auto & tempKey : keywords){
        if(0 == strcasecmp(s.c_str(), tempKey.c_str())){
            return true;
        }
    }
    return false;
}
void NPC::removeKeyword(string s) {
    if(searchKeyword(s) == true){
        for(int i=0; i < keywords.size(); i++){
            if(s.compare(keywords[i]) == 0) {
                keywords.erase(keywords.begin()+i);
            }
        }
    }else{
        cout << "The Keyword are not exist!!!"<<endl;
    }
}
void NPC::removeAllKeyword(){
    keywords.clear();
}
vector<string> NPC::getKeyword()const{
    return keywords;
}
void NPC::printVector()const{
    for(auto &  kw : keywords){
        cout << kw << endl;
    }
}
// ID -- set, get
void NPC::setID(string id) {
    npcID = id;
}
string NPC::getID() const{
    return npcID;
}



// status－－setter and getter
void NPC::setHP() {
    npcHP = 5;
}

void NPC::setAlive() {
    isAlive = true;
}

void NPC::setDamage() {
    npcDamage = 1;
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

// helper function
void NPC::checkNPC() const{
    std::cout << "          NPC check function \n";
    std::cout << "the id is                     " << getID();
    std::cout << "\n";
    std::cout << "the HP is                     " << getHP();
    std::cout << "\n";
    std::cout << "the damage is                 " << getDamage();
    std::cout << "\n";
    std::cout << "is live(1) or dead(0)?        " << getAlive();
    std::cout << "\n";
    std::cout << "description: \n" << getDes();
    std::cout << "\n";
}

// BATTLE METHOD added by Jason, edited by Jordan
/*Returns the NPC's automatic attack*/
/*TODO: in else statement, have Room notified that NPC has died
/*This should perhaps directly attack the user back instead of returning an int*/
int NPC::getHit(int damage) {
    if(npcHP > damage) { // reduce npc' HP by damage
        npcHP = npcHP - damage;
	return getDamage();
    }
    else{ // npc died
        isAlive = false;
	//NOTIFIY ROOM OF DEATH HERE
	return DEAD_DAMAGE;
    }
}


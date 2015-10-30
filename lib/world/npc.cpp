//
//  npc.cpp
//  TeamProject_cmpt373
//
//  Created by JasonYang on 2015-10-08.
//  Copyright © 2015 JasonYang. All rights reserved.
//

#include <stdio.h>
#include "npc.h"


// constructor (type, id)
// NPC::NPC(string type, string id){
// 	if (type == "monster") {
// 		Monster tempMonster;
        
//         setID(id);
// 		setName(tempMonster.getName());
//         setType(type);
//         setHP(tempMonster.getHP());
//         setAlive(tempMonster.getAlive());
//         setDamage(tempMonster.getDamage());
//         setDes(tempMonster.getDes());
        
//     }else if(type == "creature") {
//         Creature tempCreature;
        
//         setID(id);
//         setName(tempCreature.getName());
//         setType(type);
//         setHP(tempCreature.getHP());
//         setAlive(tempCreature.getAlive());
//         setDamage(int(0));
//         setDes(tempCreature.getDes());
        
//     }else {
// 		cout << "!!!!!! no such NPC !!!!!! \n";
// 	}
// }

// constructor (id)
NPC::NPC(string id){
    setID(id);
}

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
    for(int i=0; i < s.size(); i++){
        keywords.push_back(s[i]); 
    }
}
bool NPC::searchKeyword(string s)const{
    for(auto & tempKey : keywords){
        if(strcasecmp(s.c_str(),tempKey.c_str()) == 0) {
            return true;
        }
    }
    return false;
}
void NPC::removeKeyword(string s) {
    if(searchKeyword(s) == true){
        for(int i=0; i < keywords.size(); i++){
            if(strcasecmp(s.c_str(),keywords[i].c_str()) == 0){
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



// save for later (status)
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

void NPC::setDes(string des) {
    npcDes = des;
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

string NPC::getDes() const{
    return npcDes;
}

// action
void NPC::getHit() {
    if(npcHP > 1) { // reduce npc' HP by 1
        npcHP = npcHP - 1;
    }
    if(npcHP == 0){ // npc died
        isAlive = false;
    }
}



// helper function
void NPC::checkNPC() const{
    std::cout << "          NPC check function \n";
    std::cout << "the id is                     " << getID();
    std::cout << "\n";
    std::cout << "the name is                   " << getName();
    std::cout << "\n";
    std::cout << "the type is                   " << getType();
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



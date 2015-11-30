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

// 10 is the starting max health
// constructor (id)
NPC::NPC(string id) : Entity( DEFAULT_HEALTH ) {
    setID(id);
    setDamage();
}

// for copy
NPC::NPC(NPC *npc) : Entity( DEFAULT_HEALTH ) {
    npcID = npc->getID();
    npcDescription = npc->getDescription();
    longDesc = npc->getLongDesc();
    shortDesc = npc->getShortDesc();
    npcDamage = npc->getDamage();
    

    for(auto & key : npc->getKeyword()){
        keywords.push_back(key);
    }
}

// Destructor
NPC::~NPC() {

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
void NPC::setDamage() {
    npcDamage = 1;
}

int NPC::getDamage() const{
    if(isAlive()) {
        return npcDamage;
    } else {
        return 0;
    }
}

// helper function
void NPC::checkNPC() const{
    std::cout << "          NPC check function \n";
    std::cout << "the id is                     " << getID();
    std::cout << "\n";
    std::cout << "the HP is                     " << Entity::getHealth();
    std::cout << "\n";
    std::cout << "the damage is                 " << getDamage();
    std::cout << "\n";
    std::cout << "is live(1) or dead(0)?        " << isAlive();
    std::cout << "\n";
}


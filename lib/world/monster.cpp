//
//  monster.cpp
//  TeamProject_cmpt373
//
//  Created by JasonYang on 2015-10-02.
//  Copyright © 2015 JasonYang. All rights reserved.
//

#include <stdio.h>

#include "monster.h"

// constructor
Monster::Monster() {

    setName();
    setType();
    setHP();
    setAlive();
    setDamage();
    setDes();
}

// destructor
//Monster::~Monster() {
//    delete monsterName;
//    delete monsterType;
//    delete monsterHP;
//    delete monsterDamage;
//    delete isAlive;
//    delete monsterDes;
//}

//------------------------------- Set Methods ----------------------------------
// set name
void Monster::setName() {
    std::string tempNames[] = {"wizard", "baker", "grocer", "weaponsmith", "thief"};
    int randName = rand() % (5);
    
    monsterName = tempNames[randName];
}

// set Description
void Monster::setDes() {
    if (monsterName.compare("wizard") == 0) {
        monsterDes = "A wizard walks around behind the counter, talking to himself.\n";
    }else if (monsterName.compare("baker") == 0) {
        monsterDes = "The baker looks at you calmly, wiping flour from his face with one hand.\n";
    }else if (monsterName.compare("grocer") == 0) {
        monsterDes = "A grocer stands at the counter, with a slightly impatient look on his face.\n";
    }else if (monsterName.compare("weaponsmith") == 0) {
        monsterDes = "A young weaponsmith, who still has lots to learn.\n";
    }else { //(monsterName == "thief") 
        monsterDes = "A thief, all dressed in black\n";
    }
}

// set type
void Monster::setType() {
    std::string tempTypes[] = {"type1", "type2", "type3", "type4", "type5"};
    int randType = rand() % (5);
    
    monsterType =  tempTypes[randType];
}

// set HP
void Monster::setHP() {
    int randNum = rand() % (5) + 1;
    
    monsterHP = randNum;
}

// set isAlive
void Monster::setAlive() {
    isAlive = true;
}

// set Damage -- set monster's damage to int(1) temporarily
void Monster::setDamage() {
    int tempDamage = int (1);

    monsterDamage = tempDamage;
}

// ------------------------------- Get Methods ---------------------------------
// get name
string Monster::getName() const{
    return monsterName;
}

// get type
string Monster::getType() const{
    return monsterType;
}

// get HP
int Monster::getHP() const{
    return monsterHP;
}

// get isAlive
bool Monster::getAlive() const{
    return isAlive;
}

// get Damage
int Monster::getDamage() const{
    return monsterDamage;
}

// get Description
string Monster::getDes() const{
    return monsterDes;
}

// Helper Function - Check Monster's attributes
void Monster::checkMonster() {
    std::cout << "Monster check function \n";
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
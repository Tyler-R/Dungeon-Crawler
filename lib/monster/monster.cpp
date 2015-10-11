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
}

// destructor
// Monster::~Monster() {
//     delete monsterName;
//     delete monsterType;
//     delete monsterHP;
//     delete monsterDamage;
//     delete isAlive;
// }

//------------------------------- Set Methods ----------------------------------
// set name
void Monster::setName() {
    std::string tempNames[] = {"alec", "jason", "salah", "jorden", "tyler"};
    int randName = rand() % (5);
    
    monsterName = tempNames[randName];
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
    std::cout << "\n";
}



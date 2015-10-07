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

    SetName();
    SetType();
    SetHP();
    SetAlive();
    SetDamage();
}

//------------------------------- Set Methods ----------------------------------
// set name
void Monster::SetName() {
    std::string tempNames[] = {"alec", "jason", "salah", "jorden", "tyler"};
    int randName = rand() % (5);
    
    monsterName = tempNames[randName];
}

// set type
void Monster::SetType() {
    std::string tempTypes[] = {"type1", "type2", "type3", "type4", "type5"};
    int randType = rand() % (5);
    
    monsterType =  tempTypes[randType];
}

// set HP
void Monster::SetHP() {
    int randNum = rand() % (5) + 1;
    
    monsterHP = randNum;
}

// set isAlive
void Monster::SetAlive() {
    isAlive = true;
}

// set Damage -- set monster's damage to int(1) temporarily
void Monster::SetDamage() {
    int tempDamage = int (1);

    monsterDamage = tempDamage;
}

// ------------------------------- Get Methods ---------------------------------
// get name
string Monster::GetName() const{
    return monsterName;
}

// get type
string Monster::GetType() const{
    return monsterType;
}

// get HP
int Monster::GetHP() const{
    return monsterHP;
}

// get isAlive
bool Monster::GetAlive() const{
    return isAlive;
}

// get Damage
int Monster::GetDamage() const{
    return monsterDamage;
}


// Helper Function - Check Monster's attributes
void Monster::CheckMonster() {
    std::cout << "Monster check function \n";
    std::cout << "the name is                   " << GetName();
    std::cout << "\n";
    std::cout << "the type is                   " << GetType();
    std::cout << "\n";
    std::cout << "the HP is                     " << GetHP();
    std::cout << "\n";
    std::cout << "the damage is                 " << GetDamage();
    std::cout << "\n";
    std::cout << "is live(1) or dead(0)?        " << GetAlive();
    std::cout << "\n";
    std::cout << "\n";
}



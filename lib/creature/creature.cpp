//
//  creature.cpp
//  TeamProject_cmpt373
//
//  Created by JasonYang on 2015-10-03.
//  Copyright © 2015 JasonYang. All rights reserved.
//

#include <stdio.h>

#include "creature.h"

// constructor
Creature::Creature() {
    // srand(static_cast<unsigned int>(time(0)));
    
    SetType();
    SetHP();
    SetAlive();
}


// set name
void Creature::SetType() {
    std::string totalType[] = {"deel", "bear", "wolf", "lion", "tiger"};
    int randType = rand() % (5);
    creatureType = totalType[randType];
}

// set HP
void Creature::SetHP() {
    int randNum = rand() % (5) + 1;
    creatureHP = randNum;
}

// set isAlive
void Creature::SetAlive() {
    isAlive = true;
}


// get name
string Creature::GetType() const{
    return creatureType;
}

// get HP
int Creature::GetHP() const{
    return creatureHP;
}

// get isAlive
bool Creature::GetAlive() const{
    return isAlive;
}

// Helper Function - Check Creature's attributes
void Creature::CheckCreature() const {
    std::cout << "Creature check function \n";
    std::cout << "the type is                   " << GetType();
    std::cout << "\n";
    std::cout << "the HP is                     " << GetHP();
    std::cout << "\n";
    std::cout << "is live(1) or dead(0)?        " << GetAlive();
    std::cout << "\n";
    std::cout << "\n";
}
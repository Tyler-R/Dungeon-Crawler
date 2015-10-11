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
    
    setType();
    setHP();
    setAlive();
}

// destructor
Creature::~Creature() {
    delete creatureType;
    delete creatureHP;
    delete isAlive;
}


// set name
void Creature::setType() {
    std::string totalType[] = {"deel", "bear", "wolf", "lion", "tiger"};
    int randType = rand() % (5);
    creatureType = totalType[randType];
}

// set HP
void Creature::setHP() {
    int randNum = rand() % (5) + 1;
    creatureHP = randNum;
}

// set isAlive
void Creature::setAlive() {
    isAlive = true;
}


// get name
string Creature::getType() const{
    return creatureType;
}

// get HP
int Creature::getHP() const{
    return creatureHP;
}

// get isAlive
bool Creature::getAlive() const{
    return isAlive;
}

// Helper Function - Check Creature's attributes
void Creature::checkCreature() const {
    std::cout << "Creature check function \n";
    std::cout << "the type is                   " << getType();
    std::cout << "\n";
    std::cout << "the HP is                     " << getHP();
    std::cout << "\n";
    std::cout << "is live(1) or dead(0)?        " << getAlive();
    std::cout << "\n";
    std::cout << "\n";
}
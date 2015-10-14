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
    
    setName();
    setHP();
    setAlive();
    setDes();
}

// destructor
//Creature::~Creature() {
//    delete creatureName;
//    delete creatureHP;
//    delete isAlive;
//}


// set name
void Creature::setName() {
    std::string totalName[] = {"brainy", "handy", "sleepy", "hefty", "grumpy"};
    int randName = rand() % (5);
    creatureName = totalName[randName];
}

// set description
void Creature::setDes() {
    if(creatureName.compare("brainy") == 0) {
        creatureDes = "Brainy Smurf is here, numbling something to himself.\n";
    }else if (creatureName.compare("handy") == 0) {
        creatureDes = "Handy Smurf is building something here.\n";
    }else if (creatureName.compare("sleepy") == 0) {
        creatureDes = "Sleepy Smurf is sleep walking here.\n";
    }else if (creatureName.compare("hefty") == 0) {
        creatureDes = "Hefty Smurf is lifting weights here.\n";
    }else { // creatureName == "grumpy"
        creatureDes = "Grumpy Smurf is here, swearing.\n";
    }
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
string Creature::getName() const{
    return creatureName;
}

// get HP
int Creature::getHP() const{
    return creatureHP;
}

// get isAlive
bool Creature::getAlive() const{
    return isAlive;
}
// get description
string Creature::getDes() const {
    return creatureDes;
}

// Helper Function - Check Creature's attributes
void Creature::checkCreature() const {
    std::cout << "Creature check function \n";
    std::cout << "the type is                   " << getName();
    std::cout << "\n";
    std::cout << "the HP is                     " << getHP();
    std::cout << "\n";
    std::cout << "is live(1) or dead(0)?        " << getAlive();
    std::cout << "\n";
    std::cout << "Description: \n" << getDes();
    std::cout << "\n";
}
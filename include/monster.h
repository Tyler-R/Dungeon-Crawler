//
//  monster.h
//  TeamProject_cmpt373
//
//  Created by JasonYang on 2015-10-02.
//  Copyright © 2015 JasonYang. All rights reserved.
//

#ifndef monster_h
#define monster_h

#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <random>
#include <time.h>
using namespace std;

// int randNum = rand()%(max - min + 1) + min;


class Monster {
private:
    // attributes
    string monsterName; 	// name of the monster
    string monsterType; 	// type of the monster
    int monsterHP; 		// health points of the monster
    bool isAlive;		// after monsterHP reduce to 0, it considered died

    int monsterDamage;  // monster's damage
    
    // Functions
    void setName();		// set name of monster
    void setType();		// set type of monster
    void setHP();		// set HP of monster
    void setAlive();		// set isAlive of monster(must live)
    void setDamage();   // set damage for monster
    
public:
    // Constructor
    Monster();	// Default constructor
    // Destructor
    ~Monster();
    
    
    // Functions
    string getName() const;		// get name of monster
    string getType() const;		// get type of monster
    int getHP() const;		// get HP of monster
    bool getAlive() const;	// get isAlive of monster (live or dead)
    int getDamage() const;  // get monster's damage
    
    
    // HelpFunctions
    void checkMonster();
};


#endif /* monster_h */

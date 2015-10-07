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
    void SetName();		// set name of monster
    void SetType();		// set type of monster
    void SetHP();		// set HP of monster
    void SetAlive();		// set isAlive of monster(must live)
    void SetDamage();   // set damage for monster
    
public:
    // Constructors
    Monster();	// Default constructor
    
    
    // Functions
    string GetName() const;		// get name of monster
    string GetType() const;		// get type of monster
    int GetHP() const;		// get HP of monster
    bool GetAlive() const;	// get isAlive of monster (live or dead)
    int GetDamage() const;  // get monster's damage
    
    
    // HelpFunctions
    void CheckMonster();
};


#endif /* monster_h */

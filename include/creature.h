//
//  creature.h
//  TeamProject_cmpt373
//
//  Created by JasonYang on 2015-10-03.
//  Copyright © 2015 JasonYang. All rights reserved.
//

#ifndef creature_h
#define creature_h

#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <random>
#include <time.h>
using namespace std;


class Creature {

private:
    
    // attributes
    string creatureType;
    int creatureHP;
    bool isAlive;
    
    // Functions (mutators)
    void setType();
    void setHP();
    void setAlive();
    
    
    
public:
    
    // Constructors
    Creature();
    
    
    // Functions (getters)
    string getType() const;
    int getHP() const;
    bool getAlive()const;
    
    
    // Helper Functions
    void CheckCreature() const;
    
    
};


#endif /* creature_h */

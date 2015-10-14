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
    string creatureName;
    int creatureHP;
    bool isAlive;
    string creatureDes;
    
    // Functions (mutators)
    void setName();
    void setHP();
    void setAlive();
    void setDes();
    
    
public:
    
    // Constructor
    Creature();
    // Destructor
    // ~Creature();
    
    // Functions (getters)
    string getName() const;
    int getHP() const;
    bool getAlive()const;
    string getDes() const;
    
    
    // Helper Functions
    void checkCreature() const;
    
    
};


#endif /* creature_h */

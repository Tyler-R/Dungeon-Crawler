//
//  item.h
//  TeamProject_cmpt373
//
//  Created by JasonYang on 2015-10-04.
//  Copyright © 2015 JasonYang. All rights reserved.
//

#ifndef item_h
#define item_h

#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <random>
#include <time.h>
using namespace std;

class Item{

private:
    
    // attributes
    string itemType;        // the type of the item
    int itemDamage;         // the damage of the item (deal damage to player or monster)
    bool itemPositive;      // is positive damage or negative damage
    
    // functions
//    void SetType();
//    void SetDamage();
//    void SetPositive();
    void setAll();
    
    
public:
    // constructor
    Item();
    
    // functions
    string getType() const;         // return item type (or name)
    int getDamage() const;          // return the damage (positive or negative int #)
    bool getPositive() const;       // if positive restore HP, otherwise reduce HP
    
    void checkItem() const;         // Check Item attributes
    
};

#endif /* item_h */

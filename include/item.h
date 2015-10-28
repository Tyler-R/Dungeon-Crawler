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
//#include <vector>
#include <cstdlib>
#include <string>
#include <random>
#include <time.h>
using namespace std;

class Item{

private:
    
    // attributes
    string itemID;          // the Id of the item
    string itemType;        // the type of the item
    string itemName;
    //int itemDamage;         // the damage of the item (deal damage to player or monster)
    int itemBoost;          // increase the max HP of user
    
    
    // functions (3 types of items)
    void setID(string id);
    void setAll(string type);       // create potion or weapon or armour
    
    
public:
    // constructor
    Item(string type, string id);
    //destructor
    // ~Item();
    
    // functions
    string getID() const;
    string getType() const;         // return item type
    string getName() const;         // return the name of an item
    //int getDamage() const;          // return the damage (Weapon only)
    int getBoost() const;
    // helper function
    void checkItem() const;         // Check Item attributes
    
};

#endif /* item_h */

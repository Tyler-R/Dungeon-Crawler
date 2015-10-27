//
//  item.cpp
//  TeamProject_cmpt373
//
//  Created by JasonYang on 2015-10-04.
//  Copyright © 2015 JasonYang. All rights reserved.
//

#include <stdio.h>

#include "item.h"

const int boostDamage = 1;      // increase damage by 1 (weapon)
const int recoverHP = 1;        // recover hp by 1 (potion)
const int increaseMaxHP = 1;    // increase max hp by 1 (armor)

//Constructor
Item::Item(string type, string id) {
    setID(id);
    setAll(type);
}

//destructor
// Item::~Item() {
// }

void Item::setAll(string type) {
    if(type == "armor"){
        string tempName[] = {"Shield", "Cloak", "Chest", "Wrist", "Helmet"}
        itemBoost = increaseMaxHP;
    }else if(type == "weapon"){
        string tempName[] = {"Axe", "Mace", "Sword", "Bow", "Gun"}
        itemBoost = boostDamage;
    }else if(type == "potion"){
        string tempName[] = {"Heal potion", "energy potion", "revive potion", "herbs", "healing tonic"}
        itemBoost = recoverHP;
    } else {
        cout << "there is no such item, please choose "weapon", "armor", "potion" \n";
        break;
    }
    int randName = rand() % (5);
    itemName = tempName[randName];
    itemType = type;
}

void Item::setID(string id) {
    itemID = id;
}

string Item::getID() const {
    return itemID;
}

string Item::getType() const{
    return itemType;
}

string Item::getName() const{
    return itemName;
}

int Item::getBoost() const{
    return itemBoost;
}


void Item::checkItem() const {
    std::cout << "Item check function \n";
    std::cout << "the ID of the item            " << getID();
    std::cout << "\n";
    std::cout << "the type is                   " << getType();
    std::cout << "\n";
    std::cout << "the name is                   " << getName();
    std::cout << "\n";
    std::cout << "depend on the item's type     " << getBoost();
    std::cout << "\n";
    std::cout << "\n";
}
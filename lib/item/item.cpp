//
//  item.cpp
//  TeamProject_cmpt373
//
//  Created by JasonYang on 2015-10-04.
//  Copyright © 2015 JasonYang. All rights reserved.
//

#include <stdio.h>

#include "item.h"


//Constructor
Item::Item() {
//    SetType();
//    SetDamage();
//    SetPositive();
    setAll();
}

//destructor
Item::~Item() {
    delete itemType;
    delete itemDamage;
    delete itemPositive;
}

void Item::setAll(){
    std::string tempType[] = {"energy", "axe", "poison", "trap"};
    int randType = rand() % (4);
    itemType = tempType[randType];
    
    if(randType <= 1) {
        itemPositive = true;
        itemDamage = 1;
    }
    else{
        itemPositive = false;
        itemDamage = -1;
    }
}

string Item::getType() const{
    return itemType;
}

int Item::getDamage() const{
    return itemDamage;
}

bool Item::getPositive() const{
    return itemPositive;
}


void Item::checkItem() const {
    std::cout << "Item check function \n";
    std::cout << "the type is                   " << getType();
    std::cout << "\n";
    std::cout << "good(1) or bad(0) bool #      " << getPositive();
    std::cout << "\n";
    std::cout << "good(+) or bad(-) int #       " << getDamage();
    std::cout << "\n";
    std::cout << "\n";
}
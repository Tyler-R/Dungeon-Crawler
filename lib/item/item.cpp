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
    SetAll();
}

void Item::SetAll(){
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

string Item::GetType() const{
    return itemType;
}

int Item::GetDamage() const{
    return itemDamage;
}

bool Item::GetPositive() const{
    return itemPositive;
}


void Item::CheckItem() const {
    std::cout << "Item check function \n";
    std::cout << "the type is                   " << GetType();
    std::cout << "\n";
    std::cout << "good(1) or bad(0) bool #      " << GetPositive();
    std::cout << "\n";
    std::cout << "good(+) or bad(-) int #       " << GetDamage();
    std::cout << "\n";
    std::cout << "\n";
}
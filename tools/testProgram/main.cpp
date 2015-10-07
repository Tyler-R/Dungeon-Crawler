//
//  main.cpp
//  TeamProject_cmpt373
//
//  Created by JasonYang on 2015-10-02.
//  Copyright © 2015 JasonYang. All rights reserved.
//

#include <iostream>
#include "monster.h"
#include "creature.h"
#include "item.h"


int main(int argc, const char * argv[]) {
    //srand(static_cast<unsigned int>(time(0)));
    srand((unsigned)time(0));
    
    Monster monster1;
    
    Creature creature1;
    
    Item item1;

    
    monster1.CheckMonster();
    cout << "\n";
    creature1.CheckCreature();
    cout << "\n";
    item1.CheckItem();


    cout << "\n";
    cout << "\n";
    cout << "\n";
    return 0;
}


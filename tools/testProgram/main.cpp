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
#include "npc.h"
#include "object.h"


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

    cout << "\n\n";

    // check npc monster
    NPC npcMonster("monster", "id:111");
    npcMonster.CheckNPC();
    cout << "\n\n";

    // check npc creature
    NPC npcCreature("creature", "id:222");
    npcCreature.CheckNPC();
    cout << "\n\n";

    // check object
    Object objectItem("id:333");
    objectItem.CheckObject();
    cout << "\n\n";

    cout << "\n";
    cout << "\n";
    cout << "\n";
    return 0;
}


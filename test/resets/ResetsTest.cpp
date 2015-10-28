#include <iostream>

#include "NPCReset.h"
#include "DoorReset.h"
#include "ItemReset.h"

#include <memory>

int main() {

    shared_ptr<Room> room = make_shared<Room>();

    NPCReset npcReset(room);
    DoorReset doorReset(room);
    ItemReset itemReset(room);


    npcReset.performReset();
    doorReset.performReset();
    itemReset.performReset();

    return 0;
}

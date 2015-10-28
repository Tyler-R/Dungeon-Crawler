#include <iostream>

#include "reset/NPCReset.h"
#include "reset/DoorReset.h"
#include "reset/ItemReset.h"

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

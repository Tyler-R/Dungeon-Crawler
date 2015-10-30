#include <iostream>

#include "reset/NPCReset.h"
#include "reset/DoorReset.h"
#include "reset/ItemReset.h"

#include <memory>

int main() {

    shared_ptr<Room> room = make_shared<Room>();

    shared_ptr<Room> secondroom = make_shared<Room>();
    room->addDoor("3215", "north", "the second door", secondroom);

    shared_ptr<NPC> npc = make_shared<NPC>("50");
    // Item item;


    NPCReset npcReset(room, npc, 10);
    DoorReset doorReset(room, 0, "Lock");
    ItemReset itemReset(room); //item


    npcReset.performReset();
    doorReset.performReset();
    itemReset.performReset();

    return 0;
}

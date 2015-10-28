#include "reset/NPCReset.h"

NPCReset::NPCReset(std::shared_ptr<Room> room, NPC npc, int npcLimit) : Reset(room), npc(npc), npcLimit(npcLimit) {

}

NPCReset::~NPCReset() {

}

void NPCReset::performReset() {
    std::cout << "your NPC reset was performed" << std::endl;
}

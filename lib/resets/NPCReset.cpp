#include "reset/NPCReset.h"

NPCReset::NPCReset(std::shared_ptr<Room> room) : Reset(room) {

}

NPCReset::~NPCReset() {

}

void NPCReset::performReset() {
    std::cout << "your NPC reset was performed" << std::endl;
}

#include "NPCReset.h"

NPCReset::NPCReset(std::shared_ptr<Room> room) : Reset(room) {

}

NPCReset::~NPCReset() {

}

void NPCReset::performReset() {

    std::cout << "your reset was performed" << std::endl;

}

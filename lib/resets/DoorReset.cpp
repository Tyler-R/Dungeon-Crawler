#include "DoorReset.h"

DoorReset::DoorReset(std::shared_ptr<Room> room) : Reset(room) {

}

DoorReset::~DoorReset() {

}

void DoorReset::performReset() {
    std::cout << "your door reset was performed" << std::endl;
}

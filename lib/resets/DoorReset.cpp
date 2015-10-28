#include "reset/DoorReset.h"

DoorReset::DoorReset(std::shared_ptr<Room> room, int doorNumber, std::string newDoorState)
        : Reset(room), doorNumber(doorNumber), newDoorState(newDoorState) {

}

DoorReset::~DoorReset() {

}

void DoorReset::performReset() {
    std::cout << "your door reset was performed" << std::endl;
    // room.setState(doorNumber, newDoorState); (not implemented yet)
}

#include "ItemReset.h"

ItemReset::ItemReset(std::shared_ptr<Room> room) : Reset(room) {

}

ItemReset::~ItemReset() {

}

void ItemReset::performReset() {
    std::cout << "your item reset was performed" << std::endl;
}

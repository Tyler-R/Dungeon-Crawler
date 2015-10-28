#include "reset/ItemReset.h"

ItemReset::ItemReset(std::shared_ptr<Room> room) : Reset(room) {
    // TODO: once item class is created encorpporate it into this constructor
}

ItemReset::~ItemReset() {

}

void ItemReset::performReset() {
    std::cout << "TODO: add item to constructor -- your item reset was performed" << std::endl;
    // bool itemDoesNotExistInRoom = !(room.itemExistsInRoom(item.getID()));
    //
    // if(itemDoesNotExistInRoom) {
    //     room.addItem(item);
    // }
}

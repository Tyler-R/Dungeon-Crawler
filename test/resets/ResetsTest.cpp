#include <iostream>

#include "NPCReset.h"
#include <memory>

int main() {

    shared_ptr<Room> room = make_shared<Room>();

    NPCReset reset(room);

    reset.performReset();
    reset.performReset();


    std::cout << "reset made" << std::endl;

    return 0;
}

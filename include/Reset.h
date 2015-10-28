#pragma once

#include "room.h"

#include <iostream>
#include <memory>

class Reset {
public:
    Reset(std::shared_ptr<Room> room);
    ~Reset();

    virtual void performReset() = 0;

private:

    std::shared_ptr<Room> room;

};

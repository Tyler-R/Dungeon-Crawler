#pragma once

#include "Reset.h"

class DoorReset : public Reset {
public:
    DoorReset(std::shared_ptr<Room> room);
    ~DoorReset();

    virtual void performReset();

private:

};

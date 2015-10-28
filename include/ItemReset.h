#pragma once

#include "Reset.h"

class ItemReset : public Reset {
public:
    ItemReset(std::shared_ptr<Room> room);
    ~ItemReset();

    virtual void performReset();

private:

};

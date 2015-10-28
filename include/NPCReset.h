#pragma once

#include "Reset.h"

class NPCReset : public Reset {
public:
    NPCReset(std::shared_ptr<Room> room);
    ~NPCReset();

    virtual void performReset();

private:

};

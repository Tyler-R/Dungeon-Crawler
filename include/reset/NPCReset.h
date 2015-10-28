#pragma once

#include "Reset.h"
#include "npc.h"

class NPCReset : public Reset {
public:
    NPCReset(std::shared_ptr<Room> room, NPC npc, int npcLimit);
    ~NPCReset();

    virtual void performReset();

private:
    NPC npc;
    int npcLimit;
};

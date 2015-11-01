#pragma once

#include "Reset.h"
#include "npc.h"

class NPCReset : public Reset {
public:
    NPCReset( std::shared_ptr< Room > room, shared_ptr< NPC > npc, int npcLimit );
    ~NPCReset( );

    virtual void performReset( std::chrono::milliseconds currentTimeSinceEpoch );

private:
    shared_ptr< NPC > npc;
    int npcLimit;
};

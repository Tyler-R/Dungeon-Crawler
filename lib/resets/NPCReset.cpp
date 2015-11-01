#include "reset/NPCReset.h"

NPCReset::NPCReset(std::shared_ptr<Room> room, shared_ptr<NPC> npc, int npcLimit) : Reset(room), npc(npc), npcLimit(npcLimit) {

}

NPCReset::~NPCReset() {

}

void NPCReset::performReset( std::chrono::milliseconds currentTimeSinceEpoch ) {
	using namespace std::chrono;



    if( shouldPerformReset( currentTimeSinceEpoch ) ) {
    	timeLastResetWasPerformed = currentTimeSinceEpoch;

	    int numberOfNPCsInRoom = room->getNumberOfNPCsWithID(npc->getID());

	    if(numberOfNPCsInRoom < npcLimit) {
	    	shared_ptr<NPC> newNPC( new NPC( npc.get() ) );

	    	room->addNPC( newNPC );
	    }
	}
}

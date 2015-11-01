#include "reset/ItemReset.h"

ItemReset::ItemReset( std::shared_ptr<Room> room, std::shared_ptr<Item> item ) 
					: Reset( room ), item( item ) {
}

ItemReset::~ItemReset( ) {

}

void ItemReset::performReset( std::chrono::milliseconds currentTimeSinceEpoch ) {
	using namespace std::chrono;

	// don't perform reset because the recharge time of the reset has not been reached.
	if( shouldPerformReset( currentTimeSinceEpoch ) ) {
		timeLastResetWasPerformed = currentTimeSinceEpoch;

	    bool itemDoesNotExistInRoom = !( room->doesItemExist( item->getID() ) );
	    
	    if( itemDoesNotExistInRoom ) {
	    	shared_ptr< Item > newItem( new Item( item.get() ) );
	        room->addItem( newItem );
	    }
	}
}

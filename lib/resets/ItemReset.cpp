#include "reset/ItemReset.h"

ItemReset::ItemReset( std::shared_ptr<Room> room, std::shared_ptr<Item> item ) 
					: Reset( room ), item( item ) {
}

ItemReset::~ItemReset( ) {

}

void ItemReset::performReset( ) {
	cout << "Resetting Item" << endl;
    bool itemDoesNotExistInRoom = !( room->doesItemExist( item->getID() ) );
    if( itemDoesNotExistInRoom ) {
    	shared_ptr< Item > newItem( new Item( item.get() ) );
        room->addItem( newItem );
    }
	
}

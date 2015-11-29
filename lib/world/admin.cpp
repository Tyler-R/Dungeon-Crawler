/*Admin CLASS

This is a class that contains methods for the admin only  commands

Created By: Sarah Kim Dao
*/

#include "admin.h"

void Admin::setWorld(shared_ptr<World> inputWorld){
	world = inputWorld;
}

shared_ptr<World> Admin::getWorld(){
	return world;
} 

shared_ptr<Room> Admin::createRoom(){
	//string id = "newRoom" + to_string(idPos);
	shared_ptr<Room> room (new Room());

	room->setName("no_name");
	room->setId("no_id");
	room->setDesc("no_desc");
	room->setExtDesc("no_extdesc");

	return room;
}

shared_ptr<Item> Admin::createItem(){
	shared_ptr<Item> item (new Item("no_id"));
	
	item->setID("no_id");
	item->addLongDesc("no_longdesc");
	item->addShortDesc("no_shortdesc");
	item->addExtraDesc("no_extdesc");

	return item;
}

shared_ptr<NPC> Admin::createNPC(){
	shared_ptr<NPC> npc (new NPC("no_id"));
	npc->setID("no_id");
	npc->addDescription("no_description");
	npc->addLongDesc("no_longdesc");
	npc->addShortDesc("no_shortdesc");
	return npc;	
}

shared_ptr<Door*> Admin::createDoor(){

}

shared_ptr<Reset> Admin::createReset(){

}

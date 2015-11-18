#include <iostream>

#include "reset/NPCReset.h"
#include "reset/DoorReset.h"
#include "reset/ItemReset.h"


#include <memory>


void testNPCResetWithMultipleResets() {

    shared_ptr<Room> room = make_shared<Room>();
    shared_ptr<NPC> npc1 = make_shared<NPC>("50");
    shared_ptr<NPC> npc2 = make_shared<NPC>("35");


    NPCReset reset1(room, npc1, 3);
    NPCReset reset2(room, npc2, 2);


    reset1.performReset();
    reset1.performReset();
    reset1.performReset();
    reset1.performReset();
    reset1.performReset();


    reset2.performReset();
    reset2.performReset();
    reset2.performReset();    
    reset2.performReset();
    reset2.performReset();


    if(room->getNumberOfNPCsWithID("50") == 3) {
        cout << "test passed: 3 npc's with id: 50 added" << endl;
    } else {
        cout << "test failed: only " << room->getNumberOfNPCsWithID("50") << " npc's with id: 50 were added" << endl;
    }

    if(room->getNumberOfNPCsWithID("35") == 2) {
        cout << "test passed: 2 npc's with id: 35 addded" << endl;
    } else {
        cout << "test failed: only " << room->getNumberOfNPCsWithID("35") << " npc's with id: 35 were added" << endl;
    }

    if(room->getNPCs().size() == 5) {
        cout << "test passed: 5 npc's in total were added" << endl;
    } else {
        cout << "test failed: onely " << room->getNPCs().size() << " npc's were added" << endl;
    }

    auto npcs = room->getNPCs();

    if(npcs[0] == npc1) {
        cout << "test failed: not coppied properly" << endl;
    } else {
        cout << "test passed: npc not reference to object - " << npc1 << " : " << npcs[0] << endl;
    }

    if(npcs[0] == npcs[1]) {
        cout << "test failed: two npc's have same reference in room" << endl;
    } else { 
        cout << "test passed: npc's dont have the same reference - " << npcs[0] << " : " <<  npcs[1] << endl;
    }



}

void testNPCReset() {
    shared_ptr<Room> room = make_shared<Room>();
    shared_ptr<NPC> npc = make_shared<NPC>("50");

    NPCReset reset(room, npc, 3);
    reset.performReset( );

    if(room->getNumberOfNPCsWithID("50") == 1) {
        cout << "test passed: after 1 reset npc count = 1" << endl;
    } else {
        cout << "test failed: npc count != 1" << endl;
    }

    reset.performReset(  );

    if(room->getNumberOfNPCsWithID("50") == 2) {
        cout << "test passed: after 3 reset npc count = 2" << endl;
    } else {
        cout << "test failed: npc count != 2" << endl;
    }

    reset.performReset(  );

    if(room->getNumberOfNPCsWithID("50") == 3) {
        cout << "test passed: after 3 resets npc count = 3" << endl;
    } else {
        cout << "test failed: npc count != 3" << endl;
    }

    reset.performReset(  );

    if(room->getNumberOfNPCsWithID("50") == 3) {
        cout << "test passed: after 4 resets npc count = 3" << endl;
    } else {
        cout << "test failed: npc count != 3" << endl;
    }


}

void testNPCResetWithNPCLimitZero() {
    shared_ptr<Room> room = make_shared<Room>();
    shared_ptr<NPC> npc = make_shared<NPC>("50");

    NPCReset reset(room, npc, 0);

    auto npcsInRoom = room->getNPCs( );

    if(npcsInRoom.size() == 0) {
        cout << "test passed: room initialized with no npc" << endl;
    } else {
        cout << "test failed: room has npc in it upon itialization" << endl;
    }

    reset.performReset(  );

    npcsInRoom = room->getNPCs();

    if(npcsInRoom.size() == 0) {
        cout << "test passed: since npc limit is 0 no npc was added" << endl;
    } else {
        cout << "test failed: npc was added despite npc limit being 0" << endl;
    }
}

void performNPCResetTests() {
    testNPCResetWithNPCLimitZero();
    testNPCReset();
    testNPCResetWithMultipleResets();
    cout << endl;
}

void testDoorResetLocking() {
    shared_ptr<Room> room1 = make_shared<Room>();
    shared_ptr<Room> room2 = make_shared<Room>();

    room1->addDoor("12345", "north", "the door that leads north", room2);

    DoorReset reset(room1, 0, "Lock");


    // no real way to check that the change occured
    // should test what the locking / unlocking of doors does

    // we likely want to check that the player cannot move through a locked door.

    std::cout << "test passed: door compiles" << endl;

}

void performDoorResetTests() {
    testDoorResetLocking();
    cout << endl;
}

void testItemReset() {
    shared_ptr<Room> room = make_shared<Room>();
    shared_ptr<Item> item = make_shared<Item>("20");


    ItemReset reset(room, item);

    if( !room->doesItemExist( "20" ) ) {
        cout << "test passed: item does not exist in room" << endl;
    } else {
        cout << "test failed: item exists in room before reset" << endl;
    }

    reset.performReset( );

    if( room->doesItemExist( "20" ) ) {
        cout << "test passed: item now exists in room" << endl;
    } else {
        cout << "test failed: item not added to room properly" << endl;
    }
}

void performItemResetTests() {
    testItemReset();
    cout << endl;
}


int main() {
    performNPCResetTests();
    performDoorResetTests();
    performItemResetTests();


    
    return 0;
}

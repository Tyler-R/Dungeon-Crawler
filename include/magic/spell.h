#pragma once

#include <iostream>
#include <memory>

class Spell {
public:
    Spell( int cost );
    ~Spell( );

    int getCost( );


    // TODO: implement a entity class that player and enemy subclass from
    virtual void castSpell( /*Entity target*/) = 0; 

private:
	int cost;
};

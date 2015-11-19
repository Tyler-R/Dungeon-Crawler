#pragma once

#include "spell.h"

class DamageSpell : public Spell {
public:
    DamageSpell( int cost, int damage );
    ~DamageSpell( );


    // TODO: implement a entity class that player and enemy subclass from
    void castSpell( /*Entity target*/) override; 

private:
	int damage;
};

#pragma once

#include "spell.h"

class DamageSpell : public Spell {
public:
    DamageSpell( int manaCost, int minimiumLevel, std::string name, std::shared_ptr<Formula> formula );
    ~DamageSpell( );


    // TODO: implement a entity class that player and enemy subclass from
    void castSpell( User *caster, Entity *target ) override; 

private:
	int damage;
};

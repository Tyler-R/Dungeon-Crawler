#pragma once

#include <iostream>
#include <memory>
#include "Formula/Formula.h"

class Spell {
public:
    Spell( int cost, std::shared_ptr<Formula> formula );
    ~Spell( );

    int getCost( );


    // TODO: implement a entity class that player and enemy subclass from
    virtual void castSpell( /*Entity target*/) = 0; 

private:
	int manaCost;
	std::shared_ptr<Formula> formula;
};

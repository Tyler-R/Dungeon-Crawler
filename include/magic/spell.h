#pragma once

#include <iostream>
#include <memory>
#include "Formula/Formula.h"

#include "user.h"

class Spell {
public:
    Spell( int manaCost, int minimiumLevel, std::string name, std::shared_ptr<Formula> formula );
    ~Spell( );

    int getManaCost( );
    int getMinimiumLevel( );
    std::string getName( );

    std::shared_ptr<Formula> getFormula();


    // TODO: implement a entity class that player and enemy subclass from
    virtual void castSpell( User *caster/*Entity target*/ ) = 0; 

private:
	int manaCost;
	int minimiumLevel;
	std::string name;

	std::shared_ptr<Formula> formula;
};

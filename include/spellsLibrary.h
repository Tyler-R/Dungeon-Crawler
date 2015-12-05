#pragma once

#include "yaml-cpp/yaml.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "item.h"
#include <memory>
#include "magic/healingSpell.h"
#include "magic/damageSpell.h"

using namespace std;

class spellsLibrary{
	private:
		vector<shared_ptr<Spell>> spellsList;

		void parseDefenseSpellsYaml();
		void parseOffenseSpellsYaml();

	public:
		spellsLibrary();
		vector<shared_ptr<Spell>> getSpellsList();
		shared_ptr<Spell> getSpell(string spellName);
};
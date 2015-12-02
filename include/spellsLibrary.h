#include "yaml-cpp/yaml.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "item.h"
#include <memory>
#include "magic/spell.h"
#include "magic/healingspell.h"
#include "magic/damagespell.h"

using namespace std;

class spellsLibrary{
	private:
		vector<shared_ptr<Spell>> spellsList;

		void parseDefenseSpellsYaml();
		void parseOffenseSpellsYaml();
		
	public:
		spellsLibrary();
		vector<shared_ptr<Spell>> getSpellsList();
};
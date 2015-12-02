#include "yaml-cpp/yaml.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "item.h"
#include <memory>

using namespace std;

class spellsLibrary{
	public:
		void parseDefenseSpellsYaml();
		void parseOffenseSpellsYaml();
};
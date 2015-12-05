
#include "itemLibrary.h"
#include "yaml-cpp/yaml.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits.h>
#include "spellsLibrary.h"
#include "Formula/Formula.h"
#include <strings.h>


using namespace std;

spellsLibrary::spellsLibrary(){
	cout << "--Creating Spells Library ...";
	parseDefenseSpellsYaml();
	parseOffenseSpellsYaml();
	cout << "Done!" << endl;
}

// shared_ptr<Spells> spellsLibrary::create(string objectId, vector<string> objectKeywords, string objectLongDesc, string objectShortDesc, string extra){

// }



void spellsLibrary::parseDefenseSpellsYaml(){
	using namespace std;
	YAML::Node allNode = YAML::LoadFile("gameYaml/spells.yaml");
	YAML::Node spellsNode = allNode["defense"];

	string effect;
	string mana;
	string name;
	string minLevel;
	string duration;
	string hitchar;
	string hitvict;


	for(int i = 0; (unsigned)i < spellsNode.size(); i++) {
		mana = " ";
		name = " ";
		minLevel = " ";
		duration = " ";

		if (spellsNode[i]["Effect"]){
			effect = spellsNode[i]["Effect"].as<string>();
		}		
		else {
			effect = "No effect";
		}		

		if (spellsNode[i]["Hitchar"]){
			hitchar = spellsNode[i]["Hitchar"].as<string>();
		}		
		else {
			hitchar = "No Hitchar";
		}			

		if (spellsNode[i]["Hitvict"]){
			hitvict = spellsNode[i]["Hitvict"].as<string>();
		}		
		else {
			hitvict = "No Hitvict";
		}		

		if (spellsNode[i]["Duration"]){
			duration = spellsNode[i]["Duration"].as<string>();
		}		
		else {
			duration = "No Duration";
		}

		if (spellsNode[i]["Minlevel"]){
			minLevel = spellsNode[i]["Minlevel"].as<string>();
		}		
		else {
			minLevel = "No minLevel";
		} 

		mana = spellsNode[i]["Mana"].as<string>();
		name = spellsNode[i]["Name"].as<string>();

		// cout << "----DEFENSE SPELLS " << " -----" << endl;
		// cout << "Name:" << name << endl << endl;
		// cout << "Hitvict: " << hitchar << endl << endl;
		// cout << "Hitchar: " << hitvict << endl << endl;
		// cout << "Mana: " << mana << endl << endl;
		// cout << "Effect: " << effect << endl << endl;
		// cout << "minLevel: " << minLevel << endl << endl;
		// cout << "duration: " << duration << endl << endl;


		spellsList.push_back(make_shared<HealingSpell>(stoi(mana), stoi(minLevel),name,make_shared<Formula>(2,2,2,2)));

		//int manaCost, int minimiumLevel, std::string name, std::shared_ptr<Formula> formula
		

	}
}

vector<shared_ptr<Spell>> spellsLibrary::getSpellsList(){
	return spellsList;
}

shared_ptr<Spell> spellsLibrary::getSpell(string spellName){
	for (auto & spell : spellsList){
		if(0 == strcasecmp(spell->getName().c_str(), spellName.c_str())){
			return spell;
		}
	}
	
	return nullptr;
}

void spellsLibrary::parseOffenseSpellsYaml(){
	YAML::Node allNode = YAML::LoadFile("gameYaml/spells.yaml");
	YAML::Node spellsNode = allNode["offense"];

	string dammsg;
	string duration;
	string name;
	string minLevel;
	string mana;
	string damage;


	for(int i = 0; (unsigned)i < spellsNode.size(); i++) {
		mana = " ";
		name = " ";
		minLevel = " ";
		duration = " ";
		dammsg = " ";
		damage = " ";

		if (spellsNode[i]["Damage"]){
			damage = spellsNode[i]["Damage"].as<string>();
		}		
		else {
			damage = "No effect";
		}		

		if (spellsNode[i]["Dammsg"]){
			dammsg = spellsNode[i]["Dammsg"].as<string>();
		}		
		else {
			dammsg = "No Damage message";
		}			


		if (spellsNode[i]["Duration"]){
			duration = spellsNode[i]["Duration"].as<string>();
		}		
		else {
			duration = "No Duration";
		}

		if (spellsNode[i]["MinLevel"]){
			minLevel = spellsNode[i]["MinLevel"].as<string>();
		}		
		else {
			minLevel = "No minLevel";
		} 


		if (spellsNode[i]["Minlevel"]){
			minLevel = spellsNode[i]["Minlevel"].as<string>();
		}			
		else {
			minLevel = "No minLevel";
		} 

		if (spellsNode[i]["Mana"]){
			mana = spellsNode[i]["Mana"].as<string>();
		}		
		else {
			mana = "No mana";
		} 

		name = spellsNode[i]["Name"].as<string>();
		
		spellsList.push_back(make_shared<DamageSpell>(stoi(mana), stoi(minLevel),name,make_shared<Formula>(2,2,2,2)));
	}
}

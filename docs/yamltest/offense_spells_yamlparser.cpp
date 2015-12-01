//Test run with g++ -I. -g spells_yamlparser.cpp -lyaml-cpp -std=c++11 -L. -o yamltest
// ./yamltest

#include "yaml-cpp/yaml.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>


int main()
{
	using namespace std;
	YAML::Node allNode = YAML::LoadFile("spells.yaml");
	// YAML::Node allNode = YAML::LoadFile("gameYaml/spells.yaml");
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


		if (spellsNode[i]["MinLevel"]){
			minLevel = spellsNode[i]["MinLevel"].as<string>();
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
		
		cout << "----Offense SPELLS " << " -----" << endl;
		cout << "Name:" << name << endl << endl;
		cout << "Damage " << damage << endl << endl;
		cout << "Mana: " << mana << endl << endl;
		cout << "Damage message: " << dammsg << endl << endl;
		cout << "minLevel: " << minLevel << endl << endl;
		cout << "duration: " << duration << endl << endl;
	}
	return 0;
}

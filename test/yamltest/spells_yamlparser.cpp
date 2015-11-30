
//Test run with g++ -I. -g spells_yamlparser.cpp -lyaml-cpp -std=c++11 -L. -o yamltest
// ./yamltest

#include "yaml-cpp/yaml.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// void ClassName::functionName(string name){

int main()
{
	using namespace std;
	YAML::Node allNode = YAML::LoadFile("spells.yaml");
	// YAML::Node allNode = YAML::LoadFile("gameYaml/spells.yaml");
	YAML::Node spellsNode = allNode["defense"];

	string effect;
	string mana;
	string name;
	string minLevel;
	string duration;


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

		mana = spellsNode[i]["Mana"].as<string>();
		name = spellsNode[i]["Name"].as<string>();
		
		cout << "----DEFENSE SPELLS " << " -----" << endl;
		cout << "Name:" << name << endl << endl;
		cout << "mana: " << mana << endl << endl;
		cout << "Effect: " << effect << endl << endl;
		cout << "minLevel: " << minLevel << endl << endl;
		cout << "duration: " << duration << endl << endl;
	}
	return 0;
}

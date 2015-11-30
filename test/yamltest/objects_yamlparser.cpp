
//Test run with g++ -I. -g object_yamlparser.cpp -lyaml-cpp -std=c++11 -L. -o yamltest
// ./yamltest
// incompelte. Need to work on adding EXTRA description in objects


#include "yaml-cpp/yaml.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>



int main()
{

	// using namespace std;
	// YAML::Node allNode = YAML::LoadFile("gameYaml/midgaard.yaml");
	// YAML::Node objectNodes = allNode["OBJECTS"];
	
	// string objectId;
	// vector<string> objectKeywords; 
	// vector<string> objectLongDesc;
	// string objectShortDesc;
	// vector <string> extra;

	// for(int i = 0; (unsigned)i < objectNodes.size(); i++) {
	// 	extra.clear();
	// 	objectId= " ";
	// 	objectKeywords.clear();
	// 	objectLongDesc.clear();
	// 	objectShortDesc=" ";
	// 	YAML::Node extraNode = objectNodes[i]["extra"];
	// 	for (int m = 0; m < extraNode.size(); m++){
	// 		if (extraNode[m]["desc"]){
	// 			YAML::Node extraDescNode = extraNode[m]["desc"];
	// 			for(int k = 0; k < extraDescNode.size(); k++){
	// 				extra.push_back(extraDescNode[k].as<string>());
	// 			}	
	// 		} else {
	// 		extra.clear();
	// 		}			
	// 	}
	// 	cout << "longdescs: " << endl;
	// 	for (auto & longdesc : objectLongDesc) {
	// 		cout << longdesc << endl;
	// 	}
	// 	cout << endl;
	// 	for (auto & extraDesc : extra) {
	// 		cout << extraDesc << endl;
	// 	}
	// 	cout << endl;
	// 	cout << "shortdesc: " << objectShortDesc << endl<<endl;

	return 0;
}



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

	
	// string extra;
	// string objectId;
	// vector<string> objectKeywords; 
	// vector<string> objectLongDesc;
	// string objectShortDesc;

	// for(int i = 0; (unsigned)i < objectNodes.size(); i++) {
	// 	// extra =" ";
	// 	objectId= " ";
	// 	objectKeywords.clear();
	// 	objectLongDesc.clear();
	// 	objectShortDesc=" ";

	// 	cout <<"--New object Created!--"<< endl;

	// 	if (objectsNodes[i]["extra"]){
	// 		extra = objectsNodes[i]["extra"].as<string>();
	// 	}		
	// 	else {
	// 		extra = "No Extra Descripton";
	// 	}			

	// 	objectId = objectNodes[i]["id"].as<string>();


	// 	YAML::Node keywordsNode = objectNodes[i]["keywords"];
	// 	for(int k = 0; k < keywordsNode.size(); k++){
	// 		objectKeywords.push_back(keywordsNode[k].as<string>());
	// 	}

	// 	YAML::Node longdescNode = objectNodes[i]["longdesc"];
	// 	for(int k = 0; k < longdescNode.size(); k++){
	// 		objectLongDesc.push_back(longdescNode[k].as<string>());
	// 	}

	// 	objectShortDesc = objectNodes[i]["shortdesc"].as<string>(); 



		
	// 	cout << "Object Id is " << objectId << endl << endl;

	// 	cout << "Object Keywords: " << endl;
	// 	for (auto & keyword : objectKeywords) {
	// 		cout << "-" << keyword << endl;
	// 	}
	// 	cout << endl;

	// 	cout << "longdescs: " << endl;
	// 	for (auto & longdesc : objectLongDesc) {
	// 		cout << longdesc << endl;
	// 	}
	// 	cout << endl;

	// 	cout << "shortdesc: " << objectShortDesc << endl<<endl;

	// }
	return 0;
}


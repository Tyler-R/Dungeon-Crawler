/* 	
	Inventory CLASS
	Stores and controls items held by user
	Created by: Jordan Nielsen
*/
#include <algorithm>
#include "inventory.h"

using namespace std;

Inventory::Inventory(){
  inventory = new vector<Item>;
}

~Inventory::Inventory(){
  delete inventory;
}

vector<string> Inventory::getInventory(){
  vector<string> inventoryOutput = new vector<string>;
  for(string item : inventory){
    inventoryOutput.push_back(item);
  }
  return inventoryOutput;
}

/* TODO: fix the naming of item keyword as well as find out if Item or Object class is used. */
string Inventory::lookAtInventory(){
  string inventoryDescOutput = "";
  inventoryDescOutput.push_back("Your inventory contains: \n");

  if(inventory.getInventorySize() == 0){
    inventoryDescOutput.push_back("NOTHING");
    return inventoryDescOutput;
  }

  else {
    for(Item item : inventory) {
      inventoryDescOutput.push_back(" - ");
      inventoryDescOutput.push_back(item.keyword);
      inventoryDescOutput.push_back("\n");
    }
  }

  return inventoryDescOutput;
}
  

void Inventory::addItem(Item item){
  inventory.push_back(item);
  sort(inventory.begin(), inventory.end())
}

// TODO
void Inventory::removeItem(string item){
  
}

int Inventory::getInventorySize() {
  return inventory.size();
}

int Inventory::getInventoryMaxSize(){
  return inventoryMaxSize;
}

// TODO
String Inventory::useItem(string item){

}

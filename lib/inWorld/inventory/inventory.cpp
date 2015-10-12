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

vector<String> Inventory::getInventory(){
  vector<String> inventoryOutput = new vector<String>;
  for(String item : inventory){
    inventoryOutput.push_back(item);
  }
  return inventoryOutput;
}

void Inventory::addItem(Item item){
  inventory.push_back(item);
  sort(inventory.begin(), inventory.end())
}

// TODO
void Inventory::removeItem(String item){
  
}

int Inventory::getInventory() {
  return inventory.size();
}

int Inventory::getInventoryMaxSize(){
  return inventoryMaxSize;
}

// TODO
String Inventory::useItem(String item){

}

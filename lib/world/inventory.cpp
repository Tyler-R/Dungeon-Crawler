/* 	
	Inventory CLASS
	Stores and controls items held by user
	Created by: Jordan Nielsen
*/

#include "inventory.h"

Inventory::Inventory(){
}

//Copy constructor
Inventory::Inventory(Inventory &inventoryToCopy){
  vector<Item> vectorToCopy = inventoryToCopy.getInventoryItems();

  for(Item item : vectorToCopy){
   inventory.push_back(item);
  }
}

Inventory::~Inventory(){
  // delete inventory;
}

vector<Item> Inventory::getInventoryItems(){
  return inventory;
}

vector<string> Inventory::getInventoryNames(){
  vector<string> inventoryOutput = vector<string>();
  for(Item item : inventory){
    inventoryOutput.push_back(item.getName());
  }
  return inventoryOutput;
}

string Inventory::lookAtInventory(){
  string inventoryDescOutput = "";
  inventoryDescOutput + "Your inventory contains: \n";

  if(getInventorySize() == 0){
    inventoryDescOutput + "NOTHING";
    return inventoryDescOutput;
  }
  
  else {
    for(Item item : inventory) {
      inventoryDescOutput + " - ";
      inventoryDescOutput + item.getShortDesc();
      inventoryDescOutput + "\n";
    }
  }

  return inventoryDescOutput;
}

void Inventory::addItem(Item item){
  inventory.push_back(item);
}

// TODO
/*string Inventory::removeItem(string itemName){
  string result = "Item was not in your inventory";

  vector<Item>::iterator it = inventory.begin();
  for(it; it < inventory.end(); advance(it, 1)){
    //Item item = THIS NEED TO GET THE ITEM AT THE CURRENT ITERATOR!!
    if(item.searchKeyword(itemName)){
      vector<Item>::iterator it = inventory.begin();
      
      inventory.erase(this);
      result = "Item was removed from your inventory";
      break;
    }
  }
  return result;
  }*/

int Inventory::getInventorySize() {
  return inventory.size();
}

int Inventory::getInventoryMaxSize(){
  return inventoryMaxSize;
}
/*
// TODO
String Inventory::useItem(string item){

}
*/

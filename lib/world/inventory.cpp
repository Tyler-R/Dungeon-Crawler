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
  vector<shared_ptr<Item>> vectorToCopy = inventoryToCopy.getInventoryItems();

  for(shared_ptr<Item> item : vectorToCopy){
   inventory.push_back(item);
  }
}

Inventory::~Inventory(){
}

vector<shared_ptr<Item>> Inventory::getInventoryItems(){
  return inventory;
}

vector<string> Inventory::getInventoryNames(){
  vector<string> inventoryOutput = vector<string>();
  for(shared_ptr<Item> item : inventory){
    inventoryOutput.push_back(item->getName());
  }
  return inventoryOutput;
}

string Inventory::getItemName(string itemID){
  string itemName;
  for(shared_ptr<Item> item : inventory){
    if(item->getID() == itemID){
      return item->getName();
    }
  }
  return "THIS STRING IS WRONG AND SHOULDN'T BE HERE! Inventory Class - getItemName method";
}

string Inventory::lookAtInventory(){
  string inventoryDescOutput = "";
  inventoryDescOutput + "Your inventory contains: \n";

  if(getSize() == 0){
    inventoryDescOutput + "NOTHING";
    return inventoryDescOutput;
  }
  
  else {
    for(shared_ptr<Item> item : inventory) {
      inventoryDescOutput + " - ";
      inventoryDescOutput + item->getShortDesc();
      inventoryDescOutput + "\n";
    }
  }

  return inventoryDescOutput;
}

void Inventory::addItem(shared_ptr<Item> item){
  inventory.push_back(item);
}

// TODO
string Inventory::removeItem(string id){
  string result = "Item was not in your inventory";

  vector<shared_ptr<Item>>::iterator it = inventory.begin();
  for(it; it < inventory.end(); advance(it, 1)){
    shared_ptr<Item> item = *it;
    if(item->getID() == id){
      inventory.erase(it);
      result = "Item was removed from your inventory";
      break;
    }
  }
  return result;
}

int Inventory::getSize() {
  return inventory.size();
}

int Inventory::getMaxSize(){
  return inventoryMaxSize;
}

// TODO
string Inventory::useItem(string id){
  //FILL IN RETRIEVAL OF ITEM EFFECTS  

  return (removeItem(id) + " and used. /n");
}


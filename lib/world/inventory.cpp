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
    inventoryOutput.push_back(item->getShortDesc());
  }
  return inventoryOutput;
}

string Inventory::getItemName(string itemKeyword){
  string itemName;
 
  shared_ptr<Item> item = findItemByKeyword(itemKeyword);

  if(item != NULL){
    return item->getShortDesc();
  }
  else {
    return "THIS STRING IS WRONG AND SHOULDN'T BE HERE! Inventory Class - getItemName method";
  }
}

string Inventory::lookAtInventory(){
  string inventoryDescOutput = "";
  inventoryDescOutput = inventoryDescOutput + "Your inventory contains: \n";

  if(getSize() == 0){
    inventoryDescOutput + "NOTHING";
    return inventoryDescOutput;
  }
  
  else {
    for(shared_ptr<Item> item : inventory) {
      inventoryDescOutput = inventoryDescOutput + " - ";
      inventoryDescOutput = inventoryDescOutput + item->getShortDesc();
      inventoryDescOutput = inventoryDescOutput + "\n";
    }
  }

  return inventoryDescOutput;
}

void Inventory::addItem(shared_ptr<Item> item){
  inventory.push_back(item);
}

// TODO
string Inventory::removeItem(string itemKeyword){
  string result = "Item was not in your inventory";

  vector<shared_ptr<Item>>::iterator it = inventory.begin();
  for(it; it < inventory.end(); advance(it, 1)){
    shared_ptr<Item> item = *it;
    if(item->searchKeyword(itemKeyword)){
      result = item->getShortDesc() + " was removed from your inventory";
      inventory.erase(it);
      return result;
    }
  }
  return result;
}

string Inventory::getItemDescription(string itemKeyword){
  shared_ptr<Item> item = findItemByKeyword(itemKeyword);

  if(item != NULL){
    return item->getLongDesc();
  }
  else {
    string nullString = NULL;
    return nullString;
  }
}

// TODO
string Inventory::useItem(string itemKeyword){
  //FILL IN RETRIEVAL OF ITEM EFFECTS  

  return (removeItem(itemKeyword) + " and used. \n");
}

int Inventory::getSize() {
  return inventory.size();
}

int Inventory::getMaxSize(){
  return inventoryMaxSize;
}

shared_ptr<Item> Inventory::findItemByKeyword(string itemKeyword){
  for(shared_ptr<Item> item : inventory){
    if(item->searchKeyword(itemKeyword)){
      return item;
    }
  }
  shared_ptr<Item> nullPtr = NULL;
  return nullPtr;
}


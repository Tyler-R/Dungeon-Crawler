/*
Header file for inventory.cpp
Created By: Jordan Nielsen
*/

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "item.h"
using namespace std;

class Inventory {

  public:
    Inventory();

    //Copy Constructor
    Inventory(Inventory &inventory);

    ~Inventory();

    vector<shared_ptr<Item>> getInventoryItems();

    vector<string> getInventoryNames();

    string getItemName(string id);

    string lookAtInventory();

    void addItem(shared_ptr<Item> item);

    string removeItem(string itemName);

    string getItemDescription(string itemID);

    string useItem(string itemName);

    int getSize();

    int getMaxSize();

    shared_ptr<Item> findItemByID(string id);

  private:
    static const int inventoryMaxSize = 20;
    vector<shared_ptr<Item>> inventory;

  
};
    

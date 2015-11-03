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

    string lookAtInventory();

    void addItem(shared_ptr<Item> item);

    string removeItem(string itemName);

    int getSize();

    int getMaxSize();

    string useItem(string itemName);

  private:
    static const int inventoryMaxSize = 20;
    vector<shared_ptr<Item>> inventory;

  
};
    

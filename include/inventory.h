/*
Header file for inventory.cpp
Created By: Jordan Nielsen
*/

#include <iostream>
#include <string>
#include <vector>
//#include <algorithm>
#include "item.h"
using namespace std;

class Inventory {

  public:
    Inventory();

    Inventory(Inventory &inventory);

    ~Inventory();

    vector<Item> getInventoryItems();

    vector<string> getInventoryNames();

    string lookAtInventory();

    void addItem(Item item);

    //string removeItem(string itemName);

    int getInventorySize();

    int getInventoryMaxSize();

    // string useItem(string item);

  private:
    static const int inventoryMaxSize = 20;
    vector<Item> inventory;

  
};
    

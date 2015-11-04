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

    string getItemName(string itemKeyword);

    string lookAtInventory();

    void addItem(shared_ptr<Item> item);

    string removeItem(string itemKeyword);

    string getItemDescription(string itemKeyword);

    string useItem(string itemKeyword);

    int getSize();

    int getMaxSize();

    shared_ptr<Item> findItemByKeyword(string itemKeyword);

  private:
    static const int inventoryMaxSize = 20;
    vector<shared_ptr<Item>> inventory;

  
};
    

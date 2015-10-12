/*
Header file for inventory.cpp
Created By: Jordan Nielsen
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Inventory {

  public:
    Inventory();

    ~Inventory();

    vector<string> getInventory();

    void addItem(Item item);

    void removeItem(Item item);

    int getInventorySize();

    int getInventoryMaxSize();

    string useItem(string item);

  private:
    static const inventoryMaxSize = 10;
    vector<Item> inventory;

  

    

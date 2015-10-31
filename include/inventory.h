/*
Header file for inventory.cpp
Created By: Jordan Nielsen
*/

#include <iostream>
#include <string>
#include <vector>
//#include "item.h"
using namespace std;


class Item {

 public:
  Item(){
    name = "Item 1";
  }

  ~Item(){}

  string getName(){
    return name;
  }

 private:
  string name;
};





class Inventory {

  public:
    Inventory();

    ~Inventory();

    //vector<string> getInventory();

    string lookAtInventory();

    void addItem(Item item);

    void removeItem(Item item);

    int getInventorySize();

    int getInventoryMaxSize();

    string useItem(string item);

  private:
    static const int inventoryMaxSize = 10;
    vector<Item> inventory;

  
};
    

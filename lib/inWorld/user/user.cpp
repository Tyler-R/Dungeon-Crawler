/* 	User CLASS
	Contains statistics and methods for player inventory and creation
	
	Created by: Jordan Nielsen
*/

#include "user.h"
#include <iostream>
#include <string>
#include <vector>

/* Default constructor setting up basic values */
User::User(){
  setUsetType(true);
  setUserName(testUser);
  setPassword("password");
  inventory = new Inventory();
  setRoom(new Room());
  playerHealth = playerMaxHealth;
  usedDefaultConstructor = true;
}

/* User constructor for setting up basic information */
User::User(bool isAdmin, string userName, string password, Room currentRoom) {
  setUserType(isAdmin);
  setUserName(userName);
  setPassword(password);
  inventory = new Inventory();
  setRoom(currentRoom);
  playerHealth = playerMaxHealth;
  usedDefaultConstructor = false;
}

/* Ensures deletion of the player's inventory and currentRoom if default constructor used*/
User::~User() {
  delete inventory;

  if(usedDefaultConstructor){
    delete currentRoom;
  }
}

void setUserName(string userName){
  this->userName = userName;
}

string getUserName(){
  return userName;
}

void setPassword(string password){
  this->password = password;
}

string getPassword(){
  return password;
}

void setUserType(bool isAdmin){
  this->isAdmin = isAdmin;
}

bool getUserType(){
  return isAdmin;
}

void setInventory(Inventory inventory){
  this->inventory = inventory;
}

vector<Item> getInventory() {
  return inventory;
}

void setRoom(Room currentRoom){
  this->currentRoom = currentRoom;
}

Room getRoom(){
  return currentRoom;
}

void setPlayerHealth(int health){
  this->health = health;
}

int getPlayerHealth(){
  return playerHealth;
}

void setPlayerAttack(int attack){
  this->attack = attack;
}

int getPlayerAttack(){
  return playerAttack;
}

void setPlayerDefense(int defense){
  this->defense = defense);
}

int getPlayerDefense(){
  return playerDefense;
}

void setLivingStatus(bool isAlive){
  this->isAlive = isAlive;
}

bool getLivingStatus(){
  return isAlive;
}

/* prompts for a userName and requests a use check before accepting it */
/*
void createUserName() {
  bool nameIsUseable = false;

  while(nameIsUseable != true) {
    String userNameHolder;

    cout << "Select a username: " << endl;
    cin >> userNameHolder;

    nameIsUseable = checkUserName(userNameHolder);

    if(nameIsUseable) {
      userName = userNameHolder;
      break;
    }
    else {
      cout << "Sorry, userName already in use. Try again." << endl;
    }
  }
}

void createPassword() {

  bool passwordMatches = false;

  while(passwordMatches != true) {
    String userPasswordHolder;
    String userPasswordChecker;

    cout << "Select a password: " << endl;
    cin >> userPasswordHolder;

    cout << "Enter password again: " << endl;
    cin >> userPasswordChecker;

    if(userPasswordHolder == userPasswordChecker) {
      userPassword = userPasswordHolder;
      cout << "Password saved" << endl;
    }
    else {
      cout << "Passwords do not match. Try again." << endl;
    }
  }

  cout << "You've successfully created your character!" << endl;
}
*/

/* 	User CLASS
	Contains statistics and methods for player inventory and creation
	
	Created by: Jordan Nielsen
*/

#include "user.h"
#include <iostream>
#include <string>

User::User() {
  setUserType();
  createUserName();
  createPassword();
  playerHealth = playerMaxHealth;
}

User::~User() {

}

void setUserType(){
  bool isSelecting = TRUE;
  string userType;

  while(isSelecting){
    cout << "Are you an administrator?(yes/no)" << endl;
    cin >> userType;
    userType = userType.toLower();

    if(userType == "yes"){
      isAdmin = TRUE;
      isSelecting = FALSE;
    }
    else if(userType == "no"){
      isAdmin = FALSE;
      isSelecting = FALSE;
    }
    else {
      cout << "Invalid response. Please use 'yes' or 'no'" << endl;
    }
  }
}
    
/* prompts for a userName and requests a use check before accepting it */
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

vector<Item> getInventory() {
  return inventory;
}

Location getLocation(){
  return currentLocation;
}

bool isAdmin(){
  return isAdmin;
}

int getPlayerHealth(){
  return playerHealth;
}

int getPlayerAttack(){
  return playerAttack;
}

int getPlayerDefense(){
  return playerDefense;
}

#include <string>
#include <iostream>

#include "user.h"

using namespace std;

class Room {
  public:
  Room(){ roomName = "TARDIS"}

  ~Room(){}

  string getRoomName(){
    return roomName;
  }

  private:
    string roomName;
};




int main {

  bool isAdmin = true;
  string userName = "Frank";
  string password = "123456";
  Room currentRoom = new Room();
  String description = "This is a new test user";
  
  cout << "Creating new user" << endl;
  User user = new User(isAdmin, userName, password, currentRoom, description);

  cout << "User type: ";
  if(user.getUserType() == true) {
    cout << "Admin" << endl;
  }

  else {
    cout << "Standard user" << endl;
  }

  cout << "Username: " << user.getUserName() << endl;

  cout << "Password: " << user.getPassword() << endl;

  cout << "Room name: " << user.getCurrentRoom().getRoomName(); << endl;

  cout << "Description: " << user.getDescription();
  

  return 0;
}

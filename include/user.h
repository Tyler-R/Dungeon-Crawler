/*Header file for user.cpp
Created By: Jordan Nielsen
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class User {
	public:
		User();

		/*User constructor for setting up basic information*/
		User(bool isAdmin, string userName, string password, Room currentRoom);

		~User();

		/*
		void createUserName();

		void createPassword();
		*/

		void setUserName(string userName);
		string getUserName();

		void setPassword(string password);
		string getPassword();

		void setUserType(bool isAdmin);
		bool getUserType();

		void setInventory(Inventory inventory);
		vector<Item> getInventory;
		
		void setRoom(Room currentRoom);
		Room getRoom();

		void setHealth(int health);
		int getHealth();

		void setPlayerAttack(int attack);
		int getPlayerAttack();

		void setPlayerDefense(int defense);
		int getPlayerDefense();

		void setLivingStatus(bool isAlive);
		bool getLivingStatus();
		
	private:
		string userName;
		string password;
		Room currentRoom;
		vector<Item> inventory;
		bool isAdmin;
		bool isAlive;
		bool usedDefaultConstructor;

		const int playerMaxHealth = 10;
		int playerPlayerHealth;
		int playerAttack = 0;
		int playerDefense = 0;
};

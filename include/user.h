/*Header file for user.cpp
Created By: Jordan Nielsen
*/

#include <iostream>
#include <string>

using namespace std;

class User {
	public:
		User();

		~User();

		void createUserName();

		void createPassword();

		vector<Item> getInventory;

		Location getLocation();

		bool isAdmin();

		int getHealth();
		int getPlayerAttack();
		int getPlayerDefense();
		
	private:
		string userName;
		Location currentLocation;
		vector<Item> inventory;
		bool isAdmin;

		const int playerMaxHealth = 10;
		int playerPlayerHealth;
		int playerAttack = 0;
		int playerDefense = 0;
};

//TODO: Fill in rest of player stats

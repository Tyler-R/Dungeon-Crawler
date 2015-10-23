/*Header file for user.cpp
Created By: Jordan Nielsen
*/

#include <iostream>
#include "room.h"
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

		/*void setInventory(Inventory inventory);
		vector<Item> getInventory;
`		*/
		
		void setRoom(Room currentRoom);
		Room getRoom();

		void setPlayerHealth(int health);
		int getPlayerHealth();

		void setPlayerStrength(int attack);
		int getPlayerStrength();

		void setPlayerDefense(int defense);
		int getPlayerDefense();

		void setPlayerIntelligence(int playerIntelligence);
		int getPlayerIntelligence();

		void setPlayerDexterity(int playerDexterity);
		int getPlayerDexterity();

		void setPlayerCharisma(int playerCharisma);
		int getPlayerCharisma();

		void levelPlayerUp();
		int getPlayerLevel();

		void increasePlayerXP(int additionalXP);
		int getPlayerXP();

		void setLivingStatus(bool isAlive);
		bool getLivingStatus();
		
	private:
		string userName;
		string password;
		Room currentRoom;
		/* vector<Item> inventory; */
		bool isAdmin;
		bool isAlive;
		bool usedDefaultConstructor;

		const int playerMaxHealth = 10;
		int playerHealth;
		int playerStrength;
		int playerDefense;
		int playerIntelligence;
		int playerDexterity;
		int playerCharisma;

		int playerLevel;
		int playerXP;
};

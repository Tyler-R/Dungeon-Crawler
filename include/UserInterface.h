#include <ncurses.h>      
#include <string.h> 
#include <iostream>


class UserInterface
{
private:
	char str[80];
	char mesg[10]; 
	int row,col; 

public:
	UserInterface();
	~UserInterface();
	void displayUserCommand();
	void displayServerResponse(const char *serverResponse);
	void userCommand();
	std::string getUserCommand();


	
};
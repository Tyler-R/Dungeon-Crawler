#include <ncurses.h>      
#include <string.h> 
#include <iostream>


class UserInterface
{
private:
	//WINDOW *win;
	char str[80];
	char mesg[10]; 
	int row,col; 
	int countRows = 0;

	int stringPosition = 0;


public:
	UserInterface();
	~UserInterface();
	void displayUserCommand();
	void displayServerResponse(const char *serverResponse);

	void displayCommandInInputBox(std::string command);
	void userCommand();
	std::string getUserCommand();


	
};
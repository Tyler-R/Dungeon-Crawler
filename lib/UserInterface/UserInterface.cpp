#include "UserInterface.h"


UserInterface::UserInterface(){

	initscr();       // start the curses mode 
 	getmaxyx(stdscr,row,col);  //get the number of rows and columns of terminal

}

UserInterface::~UserInterface(){
	getch();
	endwin();
}


void UserInterface::userCommand(){
	mvprintw(row - 1 ,0,"%s",mesg);        //print the message at the center of the screen 
  	getstr(str);
  	clrtoeol();
}

void UserInterface::displayUserCommand(){

	//for (int i = 0; i < 4; i++){
  		mvprintw(row - row  , 0, "You Entered: %s", str); //mvprintw(LINES - 2, 0, "You Entered: %s", str);
  		clrtoeol();

  	//}
}

void UserInterface::displayServerResponse(const char *serverResponse){

	mvprintw(row - row  + 1, 0, "Server Response: %s", serverResponse); //mvprintw(LINES - 2, 0, "You Entered: %s", str);
	clrtoeol();
}


std::string UserInterface::getUserCommand(){

	return str;
}
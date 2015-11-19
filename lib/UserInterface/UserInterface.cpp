#include "UserInterface.h"


UserInterface::UserInterface(){

	initscr();      // start the curses mode 
 	getmaxyx(stdscr,row,col);  //get the number of rows and columns of terminal
 	start_color();
  	init_pair(1, COLOR_RED, COLOR_WHITE);
  	init_pair(2, COLOR_BLUE, COLOR_WHITE);
  	wbkgd(stdscr, COLOR_PAIR(2));

  	noecho();

  	//getstr(str);
  	//clrtoeol();

}

UserInterface::~UserInterface(){
	getch();
	endwin();
}
 

void UserInterface::userCommand(){

	nodelay(stdscr,1); 
	attron(COLOR_PAIR(2));
	mvprintw(row - 1 ,stringPosition ,"%s",mesg);        //print the message at the center of the screen 
	char input = getch();

	delch();
	delch();

	if(input != ERR) {
	 	str[stringPosition] = input; //getstr(str);
  		stringPosition++;
	}

	if(input == 127) {
		if(stringPosition > 0) {
			str[stringPosition - 1] = ' ';
			stringPosition--;
		}

		if(stringPosition > 0) {
			str[stringPosition - 1] = ' ';
			stringPosition--;
		}

		input = ' ';
	}

  	// clrtoeol();
  	countRows = countRows + 2;
  	if (countRows == 8){
  		countRows = 0;
  	}

  	// return input;
}

void UserInterface::displayCommandInInputBox(std::string command) {
	refresh();		
	attron(COLOR_PAIR(2));
	mvprintw(row - 1, 0, "%s", command.c_str());
}

void UserInterface::displayUserCommand(){

		refresh();
		attron(COLOR_PAIR(2));
  		mvprintw(row - row , 0, "You Entered: %s", str); //mvprintw(LINES - 2, 0, "You Entered: %s", str);
  		clrtoeol();

  		stringPosition = 0;

  		for(int i = 0; i < 80; i++) {
  			str[i] = ' ';
  		}

  		mvprintw(row - 1 , stringPosition ,"%s",mesg);
  		clrtoeol();

}

void UserInterface::displayServerResponse(const char *serverResponse){


	std::stringstream ss(serverResponse);
	std::string message;

	if (serverResponse != NULL) {
		while(std::getline(ss,message,'\n')) {
			messageLog.push_back(message);
		}
	}



}

void UserInterface::draw() {
	refresh();
	attron(COLOR_PAIR(1));

	int position = 1;
	int index = 0;
	for(auto &message : messageLog) {
		if(messageLog.size() - index < row - 1 ) {
			mvprintw(position, 0, "%s", message.c_str());
			position++;

		}
		index++;
		clrtoeol();
	}
}

void UserInterface::addMessage(std::string message) {
	messageLog.push_back(message);
}


std::string UserInterface::getUserCommand(){
	std::string command(str, 0, stringPosition);

	return command;
}








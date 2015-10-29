#include <string>
#include <iostream>

#include "world.h"

using namespace std;

int main() {
	
	cout << "hello world!" << endl;

	World newWorld;

	cout << endl << "--Setting up Current Room--" << endl;
	
	cout << endl << "--Looking at Current Room--" << endl;
	cout << newWorld.getCurrentRoom()->getDesc() << endl;

	cout << endl << "--Getting a Good Look at the Room--" << endl;
	cout << newWorld.getCurrentRoom()->lookAround()  << endl;

	return 0;
}


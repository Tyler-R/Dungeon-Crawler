1. Setup & Installation
=================

*****
1. Download Game
*****

Clone the game repository first by this command on Unix terminal
##########

    $ git clone git@csil-git1.cs.surrey.sfu.ca:373-15-3-piragua/textadventure.git
    

********
2. Install Game
********
	
Change directory to the cloned repository by this command:
#######

	$ cd textadventure/


Install game by these commands, enter one at a time:
#######

	$ cmake ./

	$ make


*******
3. Load Game
*******

load the server first, run the server by this command:
####

	$ ./bin/server

open a new terminal window and change directory to the game repository by this command:
####
	$ cd textadventure/

load the client now, run the client by this command:
####

	$ ./bin/client


.. note::

	You are asked to provide a port number , insert port number: 

	$ 8080

	You would see a white screen meaning you have launched the game properly
in order to compile libuv I have identified 4 things that must be done.
    Discalimer!!!: don't run sudo on school computers, IT will be notified.
    1. intall automake "sudo apt-get install automake"
    2. install libtoolize "sudo apt-get install libtool"
    3. all of the folders leading upto the project must have no spaces
        Ex.
        bad: "home/user/my directory/textadventure" will throw a compiler error
        good: "home/user/my_directory/textadventure" will compile nicely
    4. if "make" does not work run "sudo make"

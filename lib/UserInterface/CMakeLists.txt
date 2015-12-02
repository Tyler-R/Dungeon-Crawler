SET(CURSES_USE_NCURSES TRUE)
find_package(Curses REQUIRED)

add_library(userInterfaceLibrary UserInterface.cpp)

target_link_libraries(userInterfaceLibrary ${CURSES_LIBRARIES})
include_directories(${CURSES_INCLUDE_DIR})
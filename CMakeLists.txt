cmake_minimum_required (VERSION 2.8.12)
project (map)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(${CMAKE_SOURCE_DIR}/include)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")

add_subdirectory(lib)
add_subdirectory(tools)

add_executable(test_only tools/testProgram/main.cpp 
		lib/monster/monster.cpp 
		lib/creature/creature.cpp 
		lib/item/item.cpp
		lib/npc/npcs.cpp)
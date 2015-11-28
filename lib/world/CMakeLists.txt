add_library(world 


	world.cpp
	npc.cpp
	room.cpp	
	door.cpp
	inventory.cpp
	abilityStats.cpp
	user.cpp	
	item.cpp		
	entity.cpp
	npcLibrary.cpp
	roomLibrary.cpp
	#itemLibrary.cpp
	#resetLibrary.cpp
)

target_link_libraries(world
		      ${CMAKE_SOURCE_DIR}/ext/yaml-cpp/libyaml-cpp.a
		       )

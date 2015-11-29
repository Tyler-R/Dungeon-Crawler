add_executable(npcLibTest npcLibTest.cpp)

target_link_libraries(npcLibTest 
                       world
		       )

target_link_libraries(npcLibTest 
                       resetLibrary
		       )

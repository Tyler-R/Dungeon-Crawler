add_executable(worldTest worldTest.cpp)

target_link_libraries(worldTest
                       world
			resetLibrary
		       )

target_link_libraries(worldTest spellLibrary formulaLibrary)

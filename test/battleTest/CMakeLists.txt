add_executable(battleTest battleTest.cpp)

target_link_libraries(battleTest
                       world
		       )

target_link_libraries(battleTest resetLibrary)

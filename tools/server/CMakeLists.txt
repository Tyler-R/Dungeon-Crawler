add_executable(server ServerMain.cpp)

target_link_libraries(server serverLibrary)
target_link_libraries(server configurationLibrary)
target_link_libraries(server world)

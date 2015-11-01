add_executable(client ClientMain.cpp)

target_link_libraries(client clientLibrary)
target_link_libraries(client userInterfaceLibrary)

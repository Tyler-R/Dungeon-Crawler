add_executable(cmdtest cmdtest.cpp)

target_link_libraries(cmdtest CommandParser
                              world)

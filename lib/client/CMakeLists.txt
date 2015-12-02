add_library(clientLibrary Client.cpp)

target_link_libraries(clientLibrary ${Boost_LIBRARIES})

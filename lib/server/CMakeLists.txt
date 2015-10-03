add_library(serverLibrary Server.cpp)

target_link_libraries(serverLibrary ${Boost_LIBRARIES})

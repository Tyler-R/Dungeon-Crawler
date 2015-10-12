add_library(serverLibrary Server.cpp Session.cpp)

target_link_libraries(serverLibrary ${Boost_LIBRARIES})

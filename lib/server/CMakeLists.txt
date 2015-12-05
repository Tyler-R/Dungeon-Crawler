add_library(serverLibrary Server.cpp Session.cpp)


target_link_libraries(serverLibrary ${Boost_LIBRARIES})
target_link_libraries(serverLibrary authentication)
target_link_libraries(serverLibrary world)
target_link_libraries(serverLibrary CommandParser)
target_link_libraries(serverLibrary resetLibrary)
target_link_libraries(serverLibrary spellLibrary formulaLibrary)


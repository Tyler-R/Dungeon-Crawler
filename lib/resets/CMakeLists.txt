add_library(resetLibrary Reset.cpp NPCReset.cpp ItemReset.cpp DoorReset.cpp)

target_link_libraries(resetLibrary world)

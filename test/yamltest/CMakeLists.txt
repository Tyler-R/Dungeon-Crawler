
add_executable(npc_yamltest npc_yamlparser.cpp)
add_executable(objects_yamltest objects_yamlparser.cpp)
add_executable(rooms_yamltest rooms_yamlparser.cpp)
add_executable(reset_yamltest reset_yamlparser.cpp)

target_link_libraries(npc_yamltest ${CMAKE_SOURCE_DIR}/ext/yaml-cpp/libyaml-cpp.a)
target_link_libraries(objects_yamltest ${CMAKE_SOURCE_DIR}/ext/yaml-cpp/libyaml-cpp.a)
target_link_libraries(rooms_yamltest ${CMAKE_SOURCE_DIR}/ext/yaml-cpp/libyaml-cpp.a)
target_link_libraries(reset_yamltest ${CMAKE_SOURCE_DIR}/ext/yaml-cpp/libyaml-cpp.a)

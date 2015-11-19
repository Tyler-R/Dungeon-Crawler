
add_executable(yamltest npc_yamlparser.cpp)

target_link_libraries(yamltest ${CMAKE_SOURCE_DIR}/ext/yaml-cpp/libyaml-cpp.a)

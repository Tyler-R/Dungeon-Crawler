add_library(YamlParser YamlParser.cpp)
target_link_libraries(YamlParser ${CMAKE_CURRENT_SOURCE_DIR}/ext/yaml-cpp/libyaml-cpp.a)
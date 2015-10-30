set(YAML-CPP_USE_YAML-CPP TRUE)
find_package(yaml-cpp)

add_executable(cmdtest cmdtest.cpp)
INCLUDE_DIRECTORIES(${YAML-CPP_INCLUDE_DIR})
target_link_libraries(cmdtest CommandParser ${YAML-CPP_LIBRARIES})

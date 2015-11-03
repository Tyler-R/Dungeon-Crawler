cmake_minimum_required(VERSION 2.8.12)
project(client)
project(server)

include_directories(${CMAKE_SOURCE_DIR}/include)


set(BOOST_ROOT /opt/boost)
set(Boost_USE_STATIC_LIBS ON)
find_package(Boost COMPONENTS system)
#find_package(YamlCpp)

include_directories(${Boost_INCLUDE_DIR})


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++11") # -Wall -Werror
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")

add_subdirectory(lib)
add_subdirectory(tools)
add_subdirectory(test)
add_subdirectory(yamlFiles)


file(COPY
    ${CMAKE_CURRENT_SOURCE_DIR}/yaml/
    DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/)

add_executable(Authentication lib/authentication/Authentication.cpp
				lib/authentication/FileIO.cpp
				lib/authentication/UniqueID.cpp
				lib/authentication/UserLogin.cpp
				lib/authentication/UserSignUp.cpp
				lib/authentication/main.cpp)

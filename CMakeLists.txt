cmake_minimum_required(VERSION 2.8.12)
project(client)
project(server)

include_directories(${CMAKE_SOURCE_DIR}/include)

include(ExternalProject)


externalProject_Add(project_libuv
    URL http://dist.libuv.org/dist/v1.6.0/libuv-v1.6.0.tar.gz
    PREFIX ${CMAKE_CURRENT_BINARY_DIR}/ext/libuv-1.6.0
    UPDATE_COMMAND "${CMAKE_CURRENT_BINARY_DIR}/ext/libuv-1.6.0/src/project_libuv/autogen.sh"
    CONFIGURE_COMMAND "${CMAKE_CURRENT_BINARY_DIR}/ext/libuv-1.6.0/src/project_libuv/configure"
    BUILD_COMMAND make
    INSTALL_COMMAND make install PREFIX=${CMAKE_CURRENT_BINARY_DIR}/install/libuv-1.6.0
)

ExternalProject_GET_Property(project_libuv install_dir)

add_library(libuv STATIC IMPORTED)
set_property(TARGET libuv PROPERTY IMPORTED_LOCATION ${install_dir}/ext/libuv-1.6.0)
add_dependencies(libuv project_libuv)



set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11") # -Wall -Werror
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")

add_subdirectory(ext)
add_subdirectory(lib)
add_subdirectory(tools)

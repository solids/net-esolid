cmake_minimum_required(VERSION 3.0)
project(NetESOLID)

set(PROJECT_BINARY_DIR ${CMAKE_SOURCE_DIR}/out)
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/out)
set(CMAKE_CURRENT_BINARY_DIR ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/out)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(Protobuf)
include(deps/CMakeLists.libuv.txt)

include_directories(
  ${CMAKE_SOURCE_DIR}
  ${OCE_INCLUDE_DIRS}
  ${PROTOBUF_INCLUDE_DIRS}
  ${LIBUV_INCLUDE_DIR}
  ${CMAKE_BINARY_DIR}
)

add_executable(
  net-esolid
  src/net-esolid.cc
  ${ProtoHeaders}
  ${ProtoSources}
)


target_link_libraries (net-esolid uv)


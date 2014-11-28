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
  src/esolid/include
)

# esolid
add_definitions(-DLITTLE_ENDIAN_DOUBLE)
add_definitions(-D_Linux_i386_)

add_library(
  esolid
  src/esolid/src/VDM.cc
  src/esolid/src/bigint.cc
  src/esolid/src/bigint_matrix.cc
  src/esolid/src/bigint_vector.cc
  src/esolid/src/bigrational.cc
  src/esolid/src/bigrational_matrix.cc
  src/esolid/src/bigrational_vector.cc
  src/esolid/src/config.cc
  src/esolid/src/fpconversion.cc
  src/esolid/src/fpfilter.cc
  src/esolid/src/genbox.cc
  src/esolid/src/gencyl.cc
  src/esolid/src/genell.cc
  src/esolid/src/gentor.cc
  src/esolid/src/kbox3d.cc
  src/esolid/src/kboxco2.cc
  src/esolid/src/kcurve.cc
  src/esolid/src/kfloatpoly.cc
  src/esolid/src/kgraph.cc
  src/esolid/src/kintpoly.cc
  src/esolid/src/kpartition.cc
  src/esolid/src/kpatch.cc
  src/esolid/src/kpoint1d.cc
  src/esolid/src/kpoint2d.cc
  src/esolid/src/kratpoly.cc
  src/esolid/src/ksegment.cc
  src/esolid/src/ksolid.cc
  src/esolid/src/ksurf.cc
  src/esolid/src/pascal.cc
  src/esolid/src/pt_surf_assoc.cc
  src/esolid/src/root1.cc
  src/esolid/src/timer.cc
)


add_executable(
  net-esolid
  src/net-esolid.cc

  ${ProtoHeaders}
  ${ProtoSources}
)


target_link_libraries (net-esolid uv esolid gmp clapack cblas)


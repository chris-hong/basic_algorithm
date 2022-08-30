cmake_minimum_required (VERSION 3.8)
project ("13_snail_triangle")

add_executable (13_snail_triangle "13_snail_triangle.cpp" )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 13_snail_triangle PROPERTY CXX_STANDARD 20)
endif()
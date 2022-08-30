cmake_minimum_required (VERSION 3.8)
project ("14_pascal_triangle")

add_executable (14_pascal_triangle "14_pascal_triangle.cpp" )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 14_pascal_triangle PROPERTY CXX_STANDARD 20)
endif()
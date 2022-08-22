cmake_minimum_required (VERSION 3.8)
project ("8_char_triangle")

add_executable (8_char_triangle "8_char_triangle.cpp" )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 8_char_triangle PROPERTY CXX_STANDARD 20)
endif()
cmake_minimum_required (VERSION 3.8)
project ("16_diagonal_zigzag")

add_executable (16_diagonal_zigzag "16_diagonal_zigzag.cpp" )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 16_diagonal_zigzag PROPERTY CXX_STANDARD 20)
endif()
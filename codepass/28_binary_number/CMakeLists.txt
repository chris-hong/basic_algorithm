cmake_minimum_required (VERSION 3.8)
project ("28_binary_number")

add_executable (28_binary_number "28_binary_number.cpp" )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 28_binary_number PROPERTY CXX_STANDARD 20)
endif()
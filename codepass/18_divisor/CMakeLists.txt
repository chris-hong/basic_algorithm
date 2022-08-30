cmake_minimum_required (VERSION 3.8)
project ("18_divisor")

add_executable (18_divisor "18_divisor.cpp" )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 18_divisor PROPERTY CXX_STANDARD 20)
endif()
cmake_minimum_required (VERSION 3.8)
project ("20_get_divisor")

add_executable (20_get_divisor "20_get_divisor.cpp" )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 20_get_divisor PROPERTY CXX_STANDARD 20)
endif()
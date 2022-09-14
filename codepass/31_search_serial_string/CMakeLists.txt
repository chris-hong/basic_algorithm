cmake_minimum_required (VERSION 3.8)
project ("31_search_serial_string")

add_executable (31_search_serial_string "31_search_serial_string.cpp" )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 31_search_serial_string PROPERTY CXX_STANDARD 20)
endif()
cmake_minimum_required (VERSION 3.8)
project ("23_number_reverse")

add_executable (23_number_reverse "23_number_reverse.cpp" )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 23_number_reverse PROPERTY CXX_STANDARD 20)
endif()
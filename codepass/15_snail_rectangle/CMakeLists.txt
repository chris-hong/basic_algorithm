cmake_minimum_required (VERSION 3.8)
project ("15_snail_rectangle")

add_executable (15_snail_rectangle "15_snail_rectangle.cpp" )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 15_snail_rectangle PROPERTY CXX_STANDARD 20)
endif()
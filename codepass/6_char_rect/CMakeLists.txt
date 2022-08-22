cmake_minimum_required (VERSION 3.8)
project ("6_char_rect")

add_executable (6_char_rect "6_char_rect.cpp" )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 6_char_rect PROPERTY CXX_STANDARD 20)
endif()
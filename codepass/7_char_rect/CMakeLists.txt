cmake_minimum_required (VERSION 3.8)
project ("7_char_rect")

add_executable (7_char_rect "7_char_rect.cpp" )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 7_char_rect PROPERTY CXX_STANDARD 20)
endif()
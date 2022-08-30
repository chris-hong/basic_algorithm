cmake_minimum_required (VERSION 3.8)
project ("17_char_diamond")

add_executable (17_char_diamond "17_char_diamond.cpp" )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 17_char_diamond PROPERTY CXX_STANDARD 20)
endif()
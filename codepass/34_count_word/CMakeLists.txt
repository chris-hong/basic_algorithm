cmake_minimum_required (VERSION 3.8)
project ("34_count_word")

add_executable (34_count_word "34_count_word.cpp" )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 34_count_word PROPERTY CXX_STANDARD 20)
endif()
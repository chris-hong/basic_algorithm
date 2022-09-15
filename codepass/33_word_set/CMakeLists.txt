cmake_minimum_required (VERSION 3.8)
project ("33_word_set")

add_executable (33_word_set "33_word_set.cpp" )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 33_word_set PROPERTY CXX_STANDARD 20)
endif()
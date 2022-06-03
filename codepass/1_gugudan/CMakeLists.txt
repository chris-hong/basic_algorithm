cmake_minimum_required (VERSION 3.8)
project ("1_gugudan")

add_executable (1_gugudan "1_gugudan.cpp" )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1_gugudan PROPERTY CXX_STANDARD 20)
endif()

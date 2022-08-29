cmake_minimum_required (VERSION 3.8)
project ("02_gugudan")

add_executable (02_gugudan "02_gugudan.cpp" )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 02_gugudan PROPERTY CXX_STANDARD 20)
endif()
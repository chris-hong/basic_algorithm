cmake_minimum_required (VERSION 3.8)
project ("01_gugudan")

add_executable (01_gugudan "01_gugudan.cpp" )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 01_gugudan PROPERTY CXX_STANDARD 20)
endif()

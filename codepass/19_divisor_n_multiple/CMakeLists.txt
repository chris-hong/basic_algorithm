cmake_minimum_required (VERSION 3.8)
project ("19_divisor_n_multiple")

add_executable (19_divisor_n_multiple "19_divisor_n_multiple.cpp" )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 19_divisor_n_multiple PROPERTY CXX_STANDARD 20)
endif()
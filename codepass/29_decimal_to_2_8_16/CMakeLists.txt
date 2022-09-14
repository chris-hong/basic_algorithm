cmake_minimum_required (VERSION 3.8)
project ("29_decimal_to_2_8_16")

add_executable (29_decimal_to_2_8_16 "29_decimal_to_2_8_16.cpp" )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 29_decimal_to_2_8_16 PROPERTY CXX_STANDARD 20)
endif()
cmake_minimum_required (VERSION 3.8)
project ("26_get_prime_number")

add_executable (26_get_prime_number "26_get_prime_number.cpp" )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 26_get_prime_number PROPERTY CXX_STANDARD 20)
endif()
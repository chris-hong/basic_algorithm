cmake_minimum_required (VERSION 3.8)
project ("24_prime_n_composite")

add_executable (24_prime_n_composite "24_prime_n_composite.cpp" )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 24_prime_n_composite PROPERTY CXX_STANDARD 20)
endif()
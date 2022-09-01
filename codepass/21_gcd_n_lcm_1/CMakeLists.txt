cmake_minimum_required (VERSION 3.8)
project ("21_gcd_n_lcm_1")

add_executable (21_gcd_n_lcm_1 "21_gcd_n_lcm_1.cpp" )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 21_gcd_n_lcm_1 PROPERTY CXX_STANDARD 20)
endif()
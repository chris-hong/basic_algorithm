cmake_minimum_required (VERSION 3.8)
project ("22_gcd_n_lcm_2")

add_executable (22_gcd_n_lcm_2 "22_gcd_n_lcm_2.cpp" )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 22_gcd_n_lcm_2 PROPERTY CXX_STANDARD 20)
endif()
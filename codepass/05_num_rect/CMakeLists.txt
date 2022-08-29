cmake_minimum_required (VERSION 3.8)
project ("05_num_rect")

add_executable (05_num_rect "05_num_rect.cpp" )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 05_num_rect PROPERTY CXX_STANDARD 20)
endif()
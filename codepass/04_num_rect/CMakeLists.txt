﻿cmake_minimum_required (VERSION 3.8)
project ("04_num_rect")

add_executable (04_num_rect "04_num_rect.cpp" )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 04_num_rect PROPERTY CXX_STANDARD 20)
endif()
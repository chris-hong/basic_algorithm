﻿cmake_minimum_required (VERSION 3.8)
project ("12_star_triangle")

add_executable (12_star_triangle "12_star_triangle.cpp" )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 12_star_triangle PROPERTY CXX_STANDARD 20)
endif()
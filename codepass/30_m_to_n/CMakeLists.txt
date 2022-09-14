cmake_minimum_required (VERSION 3.8)
project ("30_m_to_n")

add_executable (30_m_to_n "30_m_to_n.cpp" )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 30_m_to_n PROPERTY CXX_STANDARD 20)
endif()
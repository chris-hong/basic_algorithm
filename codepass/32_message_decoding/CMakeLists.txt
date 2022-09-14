cmake_minimum_required (VERSION 3.8)
project ("32_message_decoding")

add_executable (32_message_decoding "32_message_decoding.cpp" )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 32_message_decoding PROPERTY CXX_STANDARD 20)
endif()
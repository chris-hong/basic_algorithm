# CMakeList.txt: codepass에 대한 CMake 프로젝트, 여기에 소스를 포함하고
# 프로젝트 특정 논리를 정의합니다.
#
cmake_minimum_required (VERSION 3.8)

project ("codepass")

add_subdirectory(1_gugudan)
add_subdirectory(2_gugudan)
add_subdirectory(3_num_rect)
add_subdirectory(4_num_rect)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1_gugudan PROPERTY CXX_STANDARD 20)
endif()
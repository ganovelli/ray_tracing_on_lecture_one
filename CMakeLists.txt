cmake_minimum_required(VERSION 3.16)

project(CGCourse LANGUAGES CXX C)
add_compile_definitions(GLM_ENABLE_EXPERIMENTAL)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)


# -------------------------------------------------
# Project sources
# -------------------------------------------------
add_subdirectory(src)
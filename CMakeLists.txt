cmake_minimum_required(VERSION 3.28)
set(CMAKE_C_COMPILER gcc)

project(INTERPRETER VERSION 0.1)

file(GLOB_RECURSE sources "src/lib/*.c")
add_library(INTERPRETER SHARED ${sources})
target_include_directories(INTERPRETER PUBLIC ./include)
set_target_properties(INTERPRETER PROPERTIES PREFIX "")
set_target_properties(INTERPRETER PROPERTIES OUTPUT_NAME "runtime")
set_target_properties(INTERPRETER PROPERTIES SUFFIX ".dll")

project(JLANG DESCRIPTION "a interpreted language" LANGUAGES C)
message("COMPILING INTERPRETER")

add_executable(JLANG "src/main.c")

set_target_properties(JLANG PROPERTIES OUTPUT_NAME "interpreter")
target_include_directories(JLANG PUBLIC ./include)
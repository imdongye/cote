set(problem template)


cmake_minimum_required(VERSION 3.5.0)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_GENERATOR_PLATFORM x64)
project(cote VERSION 0.1.0 LANGUAGES CXX)


file(GLOB_RECURSE src_files CONFIGURE_DEPENDS 
    problems/${problem}/*.h
    problems/${problem}/*.hpp
    problems/${problem}/*.c
    problems/${problem}/*.cpp
    problems/${problem}/*.txt
)
add_executable(cote ${src_files})


target_compile_definitions(cote PRIVATE
_SCL_SECURE_NO_WARNINGS  # Calling any one of the potentially unsafe methods in the Standard C++ Library
_CRT_SECURE_NO_WARNINGS  # Calling any one of the potentially unsafe methods in the CRT Library
INPUT_FILE_PATH="../../problems/${problem}/input.txt"
OUTPUT_FILE_PATH="../../problems/${problem}/output.txt"
)

set_property(DIRECTORY ${CMAKE_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT cote)
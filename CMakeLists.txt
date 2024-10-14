set(name bj-15649)


cmake_minimum_required(VERSION 3.5.0)
set(CMAKE_CXX_STANDARD 11)
project(cote VERSION 0.1.0 LANGUAGES CXX)

file(GLOB_RECURSE src_files CONFIGURE_DEPENDS 
    problems/${name}/*.cpp
)
add_executable(cote ${src_files})


cmake_minimum_required(VERSION 3.5.0)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_GENERATOR_PLATFORM x64)
project(cote VERSION 0.1.0 LANGUAGES CXX)





### if you want to build only one problem ###
set(only_one di_boj_11779)





if(only_one)
    set(subdirs ${CMAKE_CURRENT_SOURCE_DIR}/problems/${only_one})
else()
    file(GLOB subdirs ${CMAKE_CURRENT_SOURCE_DIR}/problems/*)
endif()


foreach(subdir ${subdirs})

    get_filename_component(problem ${subdir} NAME)

    file(GLOB_RECURSE files CONFIGURE_DEPENDS 
        ${subdir}/*.h
        ${subdir}/*.hpp
        ${subdir}/*.c
        ${subdir}/*.cpp
        ${subdir}/*.txt
    )
    add_executable(${problem} ${files})

    target_compile_definitions(${problem} PRIVATE
        _SCL_SECURE_NO_WARNINGS  # Calling any one of the potentially unsafe methods in the Standard C++ Library
        _CRT_SECURE_NO_WARNINGS  # Calling any one of the potentially unsafe methods in the CRT Library
        INPUT_FILE_PATH="${subdir}/input.txt"
        OUTPUT_FILE_PATH="${subdir}/output.txt"
    )

    target_compile_options(${problem} PRIVATE
        /utf-8
    )
    
endforeach()

# set_property(DIRECTORY ${CMAKE_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT template)
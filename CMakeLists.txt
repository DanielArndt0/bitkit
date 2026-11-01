cmake_minimum_required(VERSION 3.16)

project(bitkit VERSION 1.0.0 LANGUAGES NONE)

add_library(bitkit INTERFACE)
add_library(bitkit::bitkit ALIAS bitkit)

target_include_directories(bitkit INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

if(CMAKE_SOURCE_DIR STREQUAL PROJECT_SOURCE_DIR)
    enable_language(C)
    enable_language(CXX)

    add_executable(bitkit_c examples/basic.c)
    target_link_libraries(bitkit_c PRIVATE bitkit::bitkit)

    if(MSVC)
        set_target_properties(bitkit_c PROPERTIES C_STANDARD 11 C_STANDARD_REQUIRED ON)
    else()
        set_target_properties(bitkit_c PROPERTIES C_STANDARD 99 C_STANDARD_REQUIRED ON)
    endif()

    add_executable(bitkit_cpp examples/basic.cpp)
    target_link_libraries(bitkit_cpp PRIVATE bitkit::bitkit)
    set_target_properties(bitkit_cpp PROPERTIES CXX_STANDARD 11 CXX_STANDARD_REQUIRED ON)
endif()

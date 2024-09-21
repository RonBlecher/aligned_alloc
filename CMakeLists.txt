cmake_minimum_required(VERSION 2.6)

project(utils C)

add_definitions(-Wall -Werror)
if (CMAKE_C_COMPILER_VERSION VERSION_GREATER 6)
    add_definitions(-Wextra -Werror=implicit-function-declaration)
    add_definitions(-Wformat -Werror=format-security -Werror=format-nonliteral)
endif()
add_definitions(-Os -std=gnu99 -g3 -Wmissing-declarations -Wno-unused-parameter)

set(CMAKE_SHARED_LIBRARY_LINK_C_FLAGS "")

set(SOURCES main.c aligned_alloc.c)

add_executable(app ${SOURCES})

cmake_minimum_required(VERSION 3.1.0)

project(libqtlab)

find_package(Qt5 COMPONENTS Core REQUIRED)

message(STATUS "Custom include directories: ${INCLUDE_DIRS}")

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake ${CMAKE_MODULE_PATH})
set(LIBQTLAB_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR})

set(OTHER_FILES
    .gitignore
    uncrustify.cfg
    LICENSE.txt
)

add_subdirectory(libqtlab/core)
add_subdirectory(libqtlab/hw)
